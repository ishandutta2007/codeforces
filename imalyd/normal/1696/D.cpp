#include <cstdio>

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
		Get an unsigned decimal integer from input.
		*/
		template <typename unsignedIntegerType>
		inline void getUnsignedDecimalInteger(unsignedIntegerType &x)
		{
			x = 0;
			_gc();
			while (currentCharacter < '0' || currentCharacter > '9')
				_gc();
			while ('0' <= currentCharacter && currentCharacter <= '9')
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
			while (currentCharacter < '0' || currentCharacter > '9')
			{
				if (currentCharacter == '-')
					signedFlag = true;
				_gc();
			}
			while ('0' <= currentCharacter && currentCharacter <= '9')
			{
				x = (x << 1) + (x << 3) + (currentCharacter ^ 48);
				_gc();
			}
			if (signedFlag)
				x = -x;
			// printf("get %d\n",x);
		}
	};

	/*
	Text output manager class with buffer.
	*/
	template <std::size_t bufferLength = 1 << 20, std::size_t temporaryBufferLength = 256>
	class cachedTextOutput
	{
	public:
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
		inline void putUnsignedDecimalInteger(unsignedIntegerType x)
		{
			unsignedIntegerType tmp;
			do
			{
				tmp = x / 10;
				*temporaryBufferEnd++ = ((x - ((tmp << 1) + (tmp << 3))) ^ '0');
				x = tmp;
			} while (x);
			_flushTmp();
		}

		/*
		Put a signed decimal integer to outputFile.
		*/
		template <typename signedIntegerType>
		inline void putSignedDecimalInteger(signedIntegerType x)
		{
			// printf("put %d\n",x);
			if (x < 0)
			{
				x = -x;
				_pc('-');
			}
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
	};
};

namespace yaCode
{
	using yaCachedTextIO::cachedTextInput;
	using yaCachedTextIO::cachedTextOutput;
};

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

const int MN = 250005, inf = 250001;
int b[MN], d[MN], s1[MN], s2[MN];
int main()
{
	s2[0] = inf;
	b[inf] = inf;
	int t;
	in(t);
	repcnt(t)
	{
		int n;
		in(n);
		int p1 = 0, p2 = 0;
		int i, a, g;
		// std::printf("%d\n",n);

		rep(i, 1, n)
		{
			in(a);
			b[i] = a;

			while (b[s1[p1]] > a)
				--p1;
			while (b[s2[p2]] < a)
				--p2;

			// std::printf("n=%d a=%d p1=%d p2=%d\n",n,a,p1,p2);

			s1[++p1] = i;
			s2[++p2] = i;
			int ls1 = s1[p1-1];
			int i2 = *std::lower_bound(s2 + 1, s2 + p2 + 1, ls1);

			//oussp(i);
			//ouln;
			//oussp(i2);
			//ou(d[i2]);
			//ouln;
			g = MN;
			if (i2 != i)
				g = std::min(g, d[i2]);

			int ls2 = s2[p2-1];
			if (ls2 == inf)
				ls2 = 0;
			int i1 = *std::lower_bound(s1 + 1, s1 + p1 + 1, ls2);
			//oussp(i1);
			//ou(d[i1]);
			//ouln;

			if (i1 != i)
				g = std::min(g, d[i1]);

			if (i == 1)
				d[i] = 0;
			else
				d[i] = g + 1;
		}
		//ouln;
		ou(d[n]);
		ouln;
		//ouln;
	}
	// puts(_cachedTextOutput.buffer);
	return 0;
}