#include <cctype>
#include <cstdio>
#include <string>
#include<bits/stdc++.h>

namespace yaCachedTextIO
{
	/*
	Text input manager class with buffer.
	*/
	template <std::size_t bufferLength = 1 << 20>
	class cachedTextInput
	{
		std::FILE *inputFile;
		char buffer[bufferLength], *bufferStart, *bufferEnd, currentCharacter;
		bool signedFlag;

		/*
		Get a char from buffer.
		*/
		inline void _gc()
		{
			if (bufferStart == bufferEnd)
			{
				// If the buffer is empty, then reread buffer from inputFile.
				bufferEnd = (bufferStart = buffer) + std::fread(buffer, 1, bufferLength, inputFile);
				currentCharacter = bufferStart == bufferEnd ? EOF : *bufferStart++;
			}
			else
				currentCharacter = *bufferStart++;
		}

	public:
		/*
		Construct a cachedTextInput with input file _inputFile.
		*/
		inline cachedTextInput(std::FILE *_inputFile = stdin) : inputFile(_inputFile), bufferStart(NULL), bufferEnd(NULL) {}

		/*
		Get a graphical character from input.
		*/
		inline void getGraphicalCharacter(char &c)
		{
			_gc();
			while (!std::isgraph(currentCharacter))
				_gc();
			c = currentCharacter;
		}

		/*
		Get a C++-styled string from input.
		*/
		inline void getString(std::string &str)
		{
			_gc();
			while (!std::isgraph(currentCharacter))
				_gc();
			str = "";
			while (std::isgraph(currentCharacter))
			{
				str += currentCharacter;
				_gc();
			}
		}

		/*
		Get a C-styled string from input.
		*/
		inline void getString(char *str)
		{
			_gc();
			while (!std::isgraph(currentCharacter))
				_gc();
			char *strIterator = str;
			while (std::isgraph(currentCharacter))
			{
				*strIterator++ = currentCharacter;
				_gc();
			}
		}

		/*
		Get an unsigned decimal integer from input.
		*/
		template <typename unsignedIntegerType>
		inline void getUnsignedDecimalInteger(unsignedIntegerType &x)
		{
			x = 0;
			_gc();
			while (!std::isdigit(currentCharacter))
				_gc();
			while (std::isdigit(currentCharacter))
			{
				x = (x << 1) + (x << 3) + (currentCharacter ^ '0');
				_gc();
			}
		}

		/*
		Get a signed decimal integer from input.
		*/
		template <typename signedIntegerType>
		inline void getSignedDecimalInteger(signedIntegerType &x)
		{
			x = 0;
			signedFlag = false;
			_gc();
			while (!std::isdigit(currentCharacter))
			{
				signedFlag = (currentCharacter == '-');
				_gc();
			}
			while (std::isdigit(currentCharacter))
			{
				x = (x << 1) + (x << 3) + (currentCharacter ^ 48);
				_gc();
			}
			if (signedFlag)
				x = -x;
		}
	};

	/*
	Text output manager class with buffer.
	*/
	template <std::size_t bufferLength = 1 << 20, std::size_t temporaryBufferLength = 256>
	class cachedTextOutput
	{
		std::FILE *outputFile;
		char buffer[bufferLength], *bufferLimit, *bufferEnd;
		char temporaryBuffer[temporaryBufferLength], *temporaryBufferLimit, *temporaryBufferEnd;

		/*
		Flush buffer.
		*/
		inline void _flush()
		{
			std::fwrite(buffer, 1, bufferEnd - buffer, outputFile);
			bufferEnd = buffer;
		}

		/*
		Put a character to buffer.
		*/
		inline void _pc(const char &currentCharacter)
		{
			// If the buffer is full, then flush buffer.
			if (bufferEnd == bufferLimit)
				_flush();
			*bufferEnd++ = currentCharacter;
		}

		/*
		Flush temporary buffer.
		*/
		inline void _flushTmp()
		{
			while (temporaryBufferEnd != temporaryBuffer)
				_pc(*--temporaryBufferEnd);
		}

	public:
		/*
		Construct a cachedTextOutput with output file _outputFile.
		*/
		inline cachedTextOutput(std::FILE *_outputFile = stdout) : outputFile(_outputFile), bufferEnd(buffer), bufferLimit(buffer + bufferLength), temporaryBufferEnd(temporaryBuffer), temporaryBufferLimit(temporaryBuffer + temporaryBufferLength) {}

		/*
		Deconstruct a cachedTextOutput.
		*/
		inline ~cachedTextOutput()
		{
			// Flush buffer to output remaining characters in the buffer.
			_flush();
		}

		/*
		Put a character to outputFile.
		*/
		inline void putCharacter(const char &c)
		{
			_pc(c);
		}

		/*
		Put an unsigned decimal integer to outputFile.
		*/
		template <typename unsignedIntegerType>
		inline void putUnsignedDecimalInteger(const unsignedIntegerType &x)
		{
			unsignedIntegerType cur(x), tmp;
			do
			{
				tmp = cur / 10;
				*temporaryBufferEnd++ = ((cur - ((tmp << 1) + (tmp << 3))) ^ '0');
				cur = tmp;
			} while (cur);
			_flushTmp();
		}

		/*
		Put a signed decimal integer to outputFile.
		*/
		template <typename signedIntegerType>
		inline void putSignedDecimalInteger(const signedIntegerType &x)
		{
			if (x < 0)
			{
				_pc('-');
				putUnsignedDecimalInteger(-x);
			}
			else
				putUnsignedDecimalInteger(x);
		}

		/*
		Put a space to outputFile.
		*/
		inline void putSpace()
		{
			_pc(' ');
		}

		/*
		Put a line feed(LF) to outputFile.
		*/
		inline void putLine()
		{
			_pc('\n');
		}

		/*
		Put a C++-styled string.
		*/
		inline void putString(const std::string &str)
		{
			for (std::string::iterator iterator = str.begin(), iteratorEnd = str.end(); iterator != iteratorEnd; ++iterator)
				_pc(*iterator);
		}

		/*
		Put a C-styled string.
		*/
		inline void putString(const char *str)
		{
			while (*str)
				_pc(*str++);
		}
	};
};

namespace yaCode
{
	using yaCachedTextIO::cachedTextInput;
	using yaCachedTextIO::cachedTextOutput;
};

#ifndef YA_FENWICK_HEADER
#define YA_FENWICK_HEADER

#include <cstddef>
#include <vector>

namespace yaFenwickTree
{
	/*
	Gets the lowest bit value of integer x.
	*/
#define YA_LOWBIT(x) ((x) & (-(x)))

	/*
	Fenwick tree with size n.
	Note that the index starts at 1.

	REQUIREMENTS:
	For dataType a, b, c:
	a += b: a = a + b
	a + b == b + a
	(a + b) + c == a + (b + c)
	*/
	template <typename dataType, std::size_t n>
	class fenwickTree
	{
		dataType valArray[n], *valArrayBegin;

		/*
		Calculate valArray.
		*/
		inline void _cal()
		{
			for (std::size_t index(1); index <= n; ++index)
			{
				std::size_t father = index + YA_LOWBIT(index);
				if (father <= n)
					valArrayBegin[father] += valArrayBegin[index];
			}
		}

		/*
		Add(index, val)
		*/
		inline void _add(std::size_t index, const dataType &val)
		{
			for (; index <= n; index += YA_LOWBIT(index))
				valArrayBegin[index] += val;
		}

		/*
		Query(index)
		*/
		inline dataType _query(std::size_t index) const
		{
			dataType sum(0);
			for (; index; index -= YA_LOWBIT(index))
				sum += valArrayBegin[index];
			return sum;
		}

	public:
	void clr(){
		std::memset(valArray,0,sizeof(valArray));
	}
		/*
		Constructs an fenwick tree.
		*/
		inline fenwickTree() : valArrayBegin(valArray - 1) {}

		/*
		Builds an fenwick tree from an array.
		*/
		inline void build(const dataType *arr)
		{
			for (size_t index(0); index < n; ++index)
				valArray[index] = arr[index];
			_cal();
		}

		/*
		Builds an fenwick tree from a std::vector.
		*/
		inline void build(const std::vector<dataType> &arr)
		{
			if (arr.length() < n)
				throw "YA: FENWICK: [4] length of arr is less than n in function build";
			for (size_t index(0); index < n; ++index)
				valArray[index] = arr[index];
			_cal();
		}

		/*
		Constructs an fenwick tree from an array.
		*/
		inline fenwickTree(const dataType *arr) : valArrayBegin(valArray - 1)
		{
			build(arr);
		}

		/*
		Constructs an fenwick tree from a std::vector.
		*/
		inline fenwickTree(const std::vector<dataType> &arr) : valArrayBegin(valArray - 1)
		{
			build(arr);
		}

		/*
		Returns the value of node #index.

		REQUIREMENTS:
		1 <= index <= n
		*/
		inline dataType access(std::size_t index) const
		{
			if (index < 1 || index > n)
				throw "YA: FENWICK: [5] index out of bound in function access";
			return valArrayBegin[index];
		}

		/*
		Performs operation ADD(index, val).

		REQUIREMENTS:
		1 <= index <= n
		*/
		inline void add(std::size_t index, const dataType &val)
		{
			if (index < 1 || index > n)
				throw "YA: FENWICK: [1] index out of bound in function add";
			_add(index, val);
		}

		/*
		Performs operation QUERY(index).

		REQUIREMENTS:
		0 <= index <= n
		*/
		inline dataType query(std::size_t index) const
		{
			if (index < 0 || index > n)
				throw "YA: FENWICK: [2] index out of bound in function query";
			return _query(index);
		}

		/*
		Performs operation QUERY( (left, right] ).

		REQUIREMENTS:
		0 <= left <= right <= n
		For dataType a, b:
		(a - b) + b = a
		*/
		inline dataType queryInterval(std::size_t left, std::size_t right) const
		{
			if (left < 0 || left > right || right > n)
				throw "YA: FENWICK: [3] index out of bound in function queryInterval";
			return _query(right) - _query(left);
		}
	};
};

namespace yaCode
{
	using yaFenwickTree::fenwickTree;
};

#endif

using namespace yaCode;

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i, l, r) for ((i) = (l); (i) <= (r); ++(i))
#define per(i, l, r) for ((i) = (l); (i) >= (r); --(i))
#define REP(i, l, r) for ((i) = (l); (i) < (r); ++(i))
#define PER(i, l, r) for ((i) = (l); (i) > (r); --(i))
#define repcnt(i) while ((i)--)

cachedTextInput<1 << 20> _cachedTextInput;

#define in(x) _cachedTextInput.getSignedDecimalInteger((x))
#define inu(x) _cachedTextInput.getUnsignedDecimalInteger((x))

cachedTextOutput<1 << 20, 256> _cachedTextOutput;

#define ou(x) _cachedTextOutput.putSignedDecimalInteger((x))
#define ouu(x) _cachedTextOutput.putUnsignedDecimalInteger((x))

#define ousp(x) _cachedTextOutput.putSpace()
#define oussp(x) _cachedTextOutput.putSignedDecimalInteger((x)), _cachedTextOutput.putSpace()
#define ouusp(x) _cachedTextOutput.putUnsignedDecimalInteger((x)), _cachedTextOutput.putSpace()

#define ouln _cachedTextOutput.putLine()
#define ousln(x) _cachedTextOutput.putSignedDecimalInteger((x)), _cachedTextOutput.putLine()
#define ouuln(x) _cachedTextOutput.putUnsignedDecimalInteger((x)), _cachedTextOutput.putLine()

fenwickTree<int,200000> T;
int main()
{
	int t;cin>>t;repcnt(t){
		T.clr();
		int n;cin>>n;
		int i;
		ll S(0);
		rep(i,1,n){
			int a;cin>>a;
			if(a<i){
				if(a)S+=T.query(a-1);
				T.add(i,1);
			}
		}
		ouuln(S);
	}
	return 0;
}