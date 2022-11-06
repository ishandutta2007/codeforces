#include <cctype>
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

/*
Insert other templates here.
*/

using namespace yaCode;

#include <bits/stdc++.h>
using namespace std;

#define debug(format,...) fprintf(stderr,format,##__VA_ARGS__)
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
#define inch(x) _cachedTextInput.getGraphicalCharacter((x))
#define instr(x) _cachedTextInput.getString((x))

cachedTextOutput<1 << 20, 256> _cachedTextOutput;

#define ou(x) _cachedTextOutput.putSignedDecimalInteger((x))
#define ouu(x) _cachedTextOutput.putUnsignedDecimalInteger((x))

#define ousp(x) _cachedTextOutput.putSpace()
#define oussp(x) _cachedTextOutput.putSignedDecimalInteger((x)), _cachedTextOutput.putSpace()
#define ouusp(x) _cachedTextOutput.putUnsignedDecimalInteger((x)), _cachedTextOutput.putSpace()

#define ouln _cachedTextOutput.putLine()
#define ousln(x) _cachedTextOutput.putSignedDecimalInteger((x)), _cachedTextOutput.putLine()
#define ouuln(x) _cachedTextOutput.putUnsignedDecimalInteger((x)), _cachedTextOutput.putLine()

#define oustr(x) _cachedTextOutput.putString((x))

const int MN = 101;

vector<int> e[MN];
int n, ok, ec, vis[MN], d[MN];
char c[MN][MN][MN];
void add(int v, int u)
{
	//debug("+ %d %d\n",v,u);
	e[v].push_back(u);
	e[u].push_back(v);
	++ec;
}
void dfs(int v, int fa)
{
	int u;
	rep(u, 1, n) if (c[fa][u][v]&&u!=fa)
	{
		if (vis[u])
			ok = 0;
		else
		{
			vis[u] = 1;
			add(u, v);
			dfs(u, v);
		}
	}
}
void chk(int v, int fa = 0, int dep = 0)
{
	d[v] = dep;
	int u;
	for (vector<int>::iterator i = e[v].begin(), ie = e[v].end(); i != ie; ++i)
	{
		u = *i;
		if (u != fa)
		{
			chk(u, v, dep + 1);
		}
	}
}
int main()
{
	int t;
	in(t);
	repcnt(t)
	{
		in(n);
		//debug("n=%d\n",n);
		int i, j, k;
		REP(i, 1, n)
		rep(j, i + 1, n)
		{
			instr(c[i][j] + 1);
			rep(k, 1, n)
			{
				if (c[i][j][k] == '1')
					c[j][i][k] = '1';
				else
					c[j][i][k] = c[i][j][k] = 0;
			}
		}
		rep(i, 1, n) rep(k, 1, n) c[i][i][k] = '2';
		rep(i, 2, n)
		{
			// Hypo: exists edge 1--i.
			ok = 1;ec=0;

			rep(j, 1, n) vis[j] = 0;
			rep(j, 1, n) e[j].clear();

			ec = 0;
			vis[1] = vis[i] = 1;
			add(1, i);
			dfs(1, i);
			dfs(i, 1);

			//debug("ok=%d ec=%d\n",ok,ec);

			if (ok && ec == n - 1)
			{
				int ck = 1;
				int a;
				rep(k, 1, n)
				{
					chk(k);
					//rep(a,1,n)debug("%d ",d[a]);debug("\n");
					rep(a, 2, n) REP(j, 1, a)
					{
						if (((bool)c[a][j][k]) != (d[a] == d[j]))
						{
							ck = 0;
							break;
						}
					}
					if (!ck)
						break;
				}
				if (ck)
				{
					oustr("Yes\n");
					rep(a, 1, n) for (vector<int>::iterator t = e[a].begin(), te = e[a].end(); t != te; ++t)
					{
						if ((j = (*t)) < a)
						{
							//debug("%d -- %d\n",j,a);
							ouusp(j);
							ouuln(a);
						}
					}
					break;
				}
			}
		}
		if (i > n)
			oustr("No\n");
	}
	return 0;
}