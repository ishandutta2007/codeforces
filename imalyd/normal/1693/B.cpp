#include <cctype>
#include <cstddef>
#include <cstdio>
#include <string>

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
				x = (x << 1) + (x << 3) + (currentCharacter ^ '0');
				_gc();
			}
			if (signedFlag)
				x = -x;
		}

		/*
		Returns !=0 if ch is a binary digit.
		*/
		static inline int isbdigit(int ch)
		{
			return ch == 48 || ch == 49;
		}

		/*
		Get an unsigned binary integer from input.
		*/
		template <typename unsignedIntegerType>
		inline void getUnsignedBinaryInteger(unsignedIntegerType &x)
		{
			x = 0;
			_gc();
			while (!isbdigit(currentCharacter))
				_gc();
			while (isbdigit(currentCharacter))
			{
				x = (x << 1) | (currentCharacter ^ '0');
				_gc();
			}
		}

		/*
		Get a signed binary integer from input.
		*/
		template <typename signedIntegerType>
		inline void getSignedBinaryInteger(signedIntegerType &x)
		{
			x = 0;
			signedFlag = false;
			_gc();
			while (!isbdigit(currentCharacter))
			{
				signedFlag = (currentCharacter == '-');
				_gc();
			}
			while (isbdigit(currentCharacter))
			{
				x = (x << 1) | (currentCharacter ^ '0');
				_gc();
			}
			if (signedFlag)
				x = -x;
		}

		/*
		Returns !=0 if ch is an octal digit.
		*/
		static inline int isodigit(int ch)
		{
			return ch >= 48 && ch < 56;
		}

		/*
		Get an unsigned octal integer from input.
		*/
		template <typename unsignedIntegerType>
		inline void getUnsignedOctalInteger(unsignedIntegerType &x)
		{
			x = 0;
			_gc();
			while (!isodigit(currentCharacter))
				_gc();
			while (isodigit(currentCharacter))
			{
				x = (x << 3) | (currentCharacter ^ '0');
				_gc();
			}
		}

		/*
		Get a signed octal integer from input.
		*/
		template <typename signedIntegerType>
		inline void getSignedOctalInteger(signedIntegerType &x)
		{
			x = 0;
			signedFlag = false;
			_gc();
			while (!isodigit(currentCharacter))
			{
				signedFlag = (currentCharacter == '-');
				_gc();
			}
			while (isodigit(currentCharacter))
			{
				x = (x << 3) | (currentCharacter ^ '0');
				_gc();
			}
			if (signedFlag)
				x = -x;
		}

		/*
		Returns !=0 if ch is an octal digit.
		*/
		static inline char hexadecimalCharacterToNumber(const char &ch)
		{
			if (std::isdigit(ch))
				return ch ^ '0';
			if (std::isupper(ch))
				return ch - 55;
			return ch - 87;
		}

		/*
		Get an unsigned hexadecimal integer from input.
		*/
		template <typename unsignedIntegerType>
		inline void getUnsignedHexadecimalInteger(unsignedIntegerType &x)
		{
			x = 0;
			_gc();
			while (!std::isxdigit(currentCharacter))
				_gc();
			while (std::isxdigit(currentCharacter))
			{
				x = (x << 4) + hexadecimalCharacterToNumber(currentCharacter);
				_gc();
			}
		}

		/*
		Get a signed hexadecimal integer from input.
		*/
		template <typename signedIntegerType>
		inline void getSignedHexadecimalInteger(signedIntegerType &x)
		{
			x = 0;
			signedFlag = false;
			_gc();
			while (!std::isxdigit(currentCharacter))
			{
				signedFlag = (currentCharacter == '-');
				_gc();
			}
			while (std::isxdigit(currentCharacter))
			{
				x = (x << 4) + hexadecimalCharacterToNumber(currentCharacter);
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
		Put an unsigned binary integer to outputFile.
		*/
		template <typename unsignedIntegerType>
		inline void putUnsignedBinaryInteger(const unsignedIntegerType &x)
		{
			unsignedIntegerType cur(x);
			do
				*temporaryBufferEnd++ = ((cur & 1) ^ '0');
			while (cur >>= 1);
			_flushTmp();
		}

		/*
		Put a signed binary integer to outputFile.
		*/
		template <typename signedIntegerType>
		inline void putSignedBinaryInteger(const signedIntegerType &x)
		{
			if (x < 0)
			{
				_pc('-');
				putUnsignedBinaryInteger(-x);
			}
			else
				putUnsignedBinaryInteger(x);
		}

		/*
		Put an unsigned octal integer to outputFile.
		*/
		template <typename unsignedIntegerType>
		inline void putUnsignedOctalInteger(const unsignedIntegerType &x)
		{
			unsignedIntegerType cur(x);
			do
				*temporaryBufferEnd++ = ((cur & 7) ^ '0');
			while (cur >>= 3);
			_flushTmp();
		}

		/*
		Put a signed octal integer to outputFile.
		*/
		template <typename signedIntegerType>
		inline void putSignedOctalInteger(const signedIntegerType &x)
		{
			if (x < 0)
			{
				_pc('-');
				putUnsignedOctalInteger(-x);
			}
			else
				putUnsignedOctalInteger(x);
		}

		/*
		Put an unsigned hexadecimal integer to outputFile.
		*/
		template <typename unsignedIntegerType>
		inline void putUnsignedHexadecimalInteger(const unsignedIntegerType &x)
		{
			unsignedIntegerType cur(x);
			do
				*temporaryBufferEnd++ = "0123456789ABCDEF"[cur & 15];
			while (cur >>= 4);
			_flushTmp();
		}

		/*
		Put a signed hexadecimal integer to outputFile.
		*/
		template <typename signedIntegerType>
		inline void putSignedHexadecimalInteger(const signedIntegerType &x)
		{
			if (x < 0)
			{
				_pc('-');
				putUnsignedHexadecimalInteger(-x);
			}
			else
				putUnsignedHexadecimalInteger(x);
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
			for (std::string::const_iterator iterator = str.cbegin(), iteratorEnd = str.cend(); iterator != iteratorEnd; ++iterator)
				_pc(*iterator);
		}

		/*
		Put a C-styled string.
		*/
		inline void putString(const char *str)
		{
			const char *iterator(str);
			while (*iterator)
				_pc(*iterator++);
		}
	};
};

namespace yaCode
{
	using yaCachedTextIO::cachedTextInput;
	using yaCachedTextIO::cachedTextOutput;
};

/*
Insert other templates here.
*/

using namespace yaCode;

#include <bits/stdc++.h>
using namespace std;

#define debug(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
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

#define insb(x) _cachedTextInput.getSignedBinaryInteger((x))
#define inub(x) _cachedTextInput.getUnsignedBinaryInteger((x))

#define inso(x) _cachedTextInput.getSignedOctalInteger((x))
#define inuo(x) _cachedTextInput.getUnsignedOctalInteger((x))

#define insh(x) _cachedTextInput.getSignedHexadecimalInteger((x))
#define inuh(x) _cachedTextInput.getUnsignedHexadecimalInteger((x))

#define inch(x) _cachedTextInput.getGraphicalCharacter((x))
#define instr(x) _cachedTextInput.getString((x))

cachedTextOutput<1 << 20, 256> _cachedTextOutput;

#define ou(x) _cachedTextOutput.putSignedDecimalInteger((x))
#define ouu(x) _cachedTextOutput.putUnsignedDecimalInteger((x))

#define ousb(x) _cachedTextOutput.putSignedBinaryInteger((x))
#define ouub(x) _cachedTextOutput.putUnsignedBinaryInteger((x))

#define ouso(x) _cachedTextOutput.putSignedOctalInteger((x))
#define ouuo(x) _cachedTextOutput.putUnsignedOctalInteger((x))

#define oush(x) _cachedTextOutput.putSignedHexadecimalInteger((x))
#define ouuh(x) _cachedTextOutput.putUnsignedHexadecimalInteger((x))

#define ousp _cachedTextOutput.putSpace()
#define oussp(x) _cachedTextOutput.putSignedDecimalInteger((x)), _cachedTextOutput.putSpace()
#define ouusp(x) _cachedTextOutput.putUnsignedDecimalInteger((x)), _cachedTextOutput.putSpace()

#define ouln _cachedTextOutput.putLine()
#define ousln(x) _cachedTextOutput.putSignedDecimalInteger((x)), _cachedTextOutput.putLine()
#define ouuln(x) _cachedTextOutput.putUnsignedDecimalInteger((x)), _cachedTextOutput.putLine()

#define ouch(x) _cachedTextOutput.putCharacter((x))
#define oustr(x) _cachedTextOutput.putString((x))
#define oustrln(x) _cachedTextOutput.putString((x)),_cachedTextOutput.putLine()

const int MN = 200005;
int P[MN],L[MN],R[MN];
ll S[MN];
int main()
{
	int t;
	inu(t);
	while(t--){
		int n;in(n);
		int i;
		rep(i,2,n)in(P[i]);
		rep(i,1,n){
			in(L[i]);
			in(R[i]);
		}
		rep(i,1,n)S[i]=0ll;
		int a(0);
		per(i,n,1){
			if(S[i]>=L[i])S[P[i]]+=min(S[i],(ll)R[i]);
			else S[P[i]]+=R[i],++a;
		}
		ouuln(a);
	}
	return 0;
}