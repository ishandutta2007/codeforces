// Hydro submission #62c563a8c3a9fda562296b65@1657103273788
#define GCC optimize(9999999999999999999999999999999999999999999999999999999999)
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#if defined(_WIN32)
#include <Windows.h>
#include <psapi.h>
#else
#include "sys/time.h"
#endif
//#define GCC optimize(99999999999999999999999999999999999999999999999999999999999999999999999999999999)
namespace OY {
#define cin OY::inputHelper<1024, 20>::getInstance()
#define getchar() ({char c=cin.getChar_Checked();cin.next();c;})
#define cout OY::outputHelper<1048576>::getInstance()
#define putchar cout.putChar
#define endl '\n'
#define putlog(...) OY::printLog(", ", __VA_ARGS__)
    template <uint64_t _BufferSize = 1024, uint64_t _BlockSize = 20>
    class inputHelper {
        FILE *m_filePtr;
        char m_buf[_BufferSize], *m_end, *m_cursor;
        bool m_ok;
        void flush() {
            uint64_t a = m_end - m_cursor;
            if (a >= _BlockSize) return;
            memmove(m_buf, m_cursor, a);
            uint64_t b = fread(m_buf + a, 1, _BufferSize - a, m_filePtr);
            m_cursor = m_buf;
            if (a + b < _BufferSize) {
                m_end = m_buf + a + b;
                *m_end = EOF;
            }
        }

    public:
        explicit inputHelper(const char *inputFileName) : m_ok(true) {
            if (!*inputFileName)
                m_filePtr = stdin;
            else
                m_filePtr = fopen(inputFileName, "rt");
            m_end = m_cursor = m_buf + _BufferSize;
        }
        ~inputHelper() { fclose(m_filePtr); }
        static inputHelper<_BufferSize, _BlockSize> &getInstance() {
#ifdef OY_LOCAL
            static inputHelper<_BufferSize, _BlockSize> s_obj("in.txt");
#else
            static inputHelper<_BufferSize, _BlockSize> s_obj("");
#endif
            return s_obj;
        }
        static constexpr bool isBlank(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }
        static constexpr bool isEndline(char c) { return c == '\n' || c == EOF; }
        const char &getChar_Checked() {
            if (m_cursor < m_end) return *m_cursor;
            uint64_t b = fread(m_buf, 1, _BufferSize, m_filePtr);
            m_cursor = m_buf;
            if (b < _BufferSize) {
                m_end = m_buf + b;
                *m_end = EOF;
            }
            return *m_cursor;
        }
        const char &getChar_Unchecked() const { return *m_cursor; }
        void next() { ++m_cursor; }
        void setState(bool _ok) { m_ok = _ok; }
        template <typename _Tp, std::enable_if_t<std::is_signed_v<_Tp> & std::is_integral_v<_Tp>> * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            while (isBlank(getChar_Checked())) next();
            flush();
            if (getChar_Unchecked() == '-') {
                next();
                if (isdigit(getChar_Unchecked())) {
                    ret = -(getChar_Unchecked() - '0');
                    while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 - (getChar_Unchecked() - '0');
                } else
                    m_ok = false;
            } else {
                if (isdigit(getChar_Unchecked())) {
                    ret = getChar_Unchecked() - '0';
                    while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
                } else
                    m_ok = false;
            }
            return *this;
        }
        template <typename _Tp, std::enable_if_t<std::is_unsigned_v<_Tp> & std::is_integral_v<_Tp>> * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            while (isBlank(getChar_Checked())) next();
            flush();
            if (isdigit(getChar_Unchecked())) {
                ret = getChar_Unchecked() - '0';
                while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
            } else
                m_ok = false;
            return *this;
        }
        template <typename _Tp, std::enable_if_t<std::is_floating_point_v<_Tp>> * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            bool neg = false, integer = false, decimal = false;
            while (isBlank(getChar_Checked())) next();
            flush();
            if (getChar_Unchecked() == '-') {
                neg = true;
                next();
            }
            if (!isdigit(getChar_Unchecked()) && getChar_Unchecked() != '.') {
                m_ok = false;
                return *this;
            }
            if (isdigit(getChar_Unchecked())) {
                integer = true;
                ret = getChar_Unchecked() - '0';
                while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
            }
            if (getChar_Unchecked() == '.') {
                next();
                if (isdigit(getChar_Unchecked())) {
                    if (!integer) ret = 0;
                    decimal = true;
                    _Tp unit = 0.1;
                    ret += unit * (getChar_Unchecked() - '0');
                    while (next(), isdigit(getChar_Unchecked())) {
                        unit *= 0.1;
                        ret += unit * (getChar_Unchecked() - '0');
                    }
                }
            }
            if (!integer && !decimal)
                m_ok = false;
            else if (neg)
                ret = -ret;
            return *this;
        }
        inputHelper<_BufferSize, _BlockSize> &operator>>(char &ret) {
            while (isBlank(getChar_Checked())) next();
            ret = getChar_Checked();
            next();
            return *this;
        }
        inputHelper<_BufferSize, _BlockSize> &operator>>(std::string &ret) {
            while (isBlank(getChar_Checked())) next();
            if (getChar_Checked() != EOF) {
                ret.clear();
                do {
                    ret += getChar_Checked();
                    next();
                } while (!isBlank(getChar_Checked()) && getChar_Unchecked() != EOF);
            } else
                m_ok = false;
            return *this;
        }
        explicit operator bool() { return m_ok; }
    };
    template <uint64_t _BufferSize = 1048576>
    class outputHelper {
        FILE *m_filePtr = nullptr;
        char m_buf[_BufferSize], *m_end, *m_cursor;
        char m_tempBuf[50], *m_tempBufCursor, *m_tempBufDot;
        uint64_t m_floatReserve, m_floatRatio;

    public:
        outputHelper(const char *outputFileName, int prec = 6) : m_end(m_buf + _BufferSize) {
            if (!*outputFileName)
                m_filePtr = stdout;
            else
                m_filePtr = fopen(outputFileName, "wt");
            m_cursor = m_buf;
            m_tempBufCursor = m_tempBuf;
            precision(prec);
        }
        static outputHelper<_BufferSize> &getInstance() {
#ifdef OY_LOCAL
            static outputHelper<_BufferSize> s_obj("out.txt");
#else
            static outputHelper<_BufferSize> s_obj("");
#endif
            return s_obj;
        }
        ~outputHelper() {
            flush();
            fclose(m_filePtr);
        }
        void precision(int prec) {
            m_floatReserve = prec;
            m_floatRatio = pow(10, prec);
            m_tempBufDot = m_tempBuf + prec;
        }
        outputHelper<_BufferSize> &flush() {
            fwrite(m_buf, 1, m_cursor - m_buf, m_filePtr);
            fflush(m_filePtr);
            m_cursor = m_buf;
            return *this;
        }
        void putChar(const char &c) {
            if (m_cursor == m_end) flush();
            *m_cursor++ = c;
        }
        void putS(const char *c) {
            while (*c) putChar(*c++);
        }
        template <typename _Tp, std::enable_if_t<std::is_signed_v<_Tp> & std::is_integral_v<_Tp>> * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            _Tp _ret = _Tp(ret);
            if (_ret >= 0) {
                do {
                    *m_tempBufCursor++ = '0' + _ret % 10;
                    _ret /= 10;
                } while (_ret);
                do putChar(*--m_tempBufCursor);
                while (m_tempBufCursor > m_tempBuf);
            } else {
                putChar('-');
                do {
                    *m_tempBufCursor++ = '0' - _ret % 10;
                    _ret /= 10;
                } while (_ret);
                do putChar(*--m_tempBufCursor);
                while (m_tempBufCursor > m_tempBuf);
            }
            return *this;
        }
        template <typename _Tp, std::enable_if_t<std::is_unsigned_v<_Tp> & std::is_integral_v<_Tp>> * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            _Tp _ret = _Tp(ret);
            do {
                *m_tempBufCursor++ = '0' + _ret % 10;
                _ret /= 10;
            } while (_ret);
            do putChar(*--m_tempBufCursor);
            while (m_tempBufCursor > m_tempBuf);
            return *this;
        }
        template <typename _Tp, std::enable_if_t<std::is_floating_point_v<_Tp>> * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            if (ret < 0) {
                putChar('-');
                return *this << -ret;
            }
            _Tp _ret = ret * m_floatRatio;
            uint64_t integer = _ret;
            if (_ret - integer >= 0.4999999999) integer++;
            do {
                *m_tempBufCursor++ = '0' + integer % 10;
                integer /= 10;
            } while (integer);
            if (m_tempBufCursor > m_tempBufDot) {
                do putChar(*--m_tempBufCursor);
                while (m_tempBufCursor > m_tempBufDot);
                putChar('.');
            } else {
                putS("0.");
                for (int i = m_tempBufDot - m_tempBufCursor; i--;) putChar('0');
            }
            do putChar(*--m_tempBufCursor);
            while (m_tempBufCursor > m_tempBuf);
            return *this;
        }
        outputHelper<_BufferSize> &operator<<(const char &ret) {
            putChar(ret);
            return *this;
        }
        outputHelper<_BufferSize> &operator<<(const std::string &ret) {
            putS(ret.data());
            return *this;
        }
    };
    template <uint64_t _BufferSize, uint64_t _BlockSize>
    inputHelper<_BufferSize, _BlockSize> &getline(inputHelper<_BufferSize, _BlockSize> &ih, std::string &ret) {
        ret.clear();
        if (ih.getChar_Checked() == EOF)
            ih.setState(0);
        else {
            while (!inputHelper<_BufferSize, _BlockSize>::isEndline(ih.getChar_Checked())) {
                ret += ih.getChar_Unchecked();
                ih.next();
            }
            ih.next();
        }
        return ih;
    }
    template <typename D, typename T, typename... S>
    void printLog(D delim, const T &x, S... rest) {
        cout << x;
        if constexpr (sizeof...(rest) > 0) {
            cout << delim;
            printLog(delim, rest...);
        }
    }
}
using OY::getline;
using std::vector;
using std::queue;
using std::min;

#define ll long long
const int N=1e4+1;
const int K=10;
namespace Flow
{
	const int V=N;
	const int E=N;
	const int inf=0x3f3f3f3f;
	int n;
	struct edge
	{
		int to,nxt,val;
	}e[E*2];
	int cur[V],head[V],cnte;
	void add_edge(int u,int v,int w)
	{
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	void add(int u,int v,int w)
	{
		add_edge(u,v,w);
		add_edge(v,u,0);
	}
	int deep[V];
	bool bfs(int S,int T)
	{
		for (int i=0;i<=n;i++) cur[i]=head[i],deep[i]=-1;
		queue<int>q;
		q.push(S);
		deep[S]=0;
		while (!q.empty())
		{
			int now=q.front(); q.pop();
			for (int i=head[now];i;i=e[i].nxt)
			if (e[i].val)
			{
				int to=e[i].to;
				if (deep[to]<0) deep[to]=deep[now]+1,q.push(to);
				if (to==T) return 1;
			}
		}
		return deep[T]>=0;
	}
	int dfs(int now,int T,int flow)
	{
		if (now==T) return flow;
		if (!flow) return 0;
		int ret=0,tmp=0;
		for (int i=cur[now];i;cur[now]=i=e[i].nxt)
		{
			int to=e[i].to,val=e[i].val;
			if (!val||deep[to]!=deep[now]+1) continue;
			if (tmp=dfs(to,T,min(flow,val)))
			{
				ret+=tmp,flow-=tmp;
				e[i].val-=tmp,e[i^1].val+=tmp;
				if (!flow) return ret;
			}
		}
		return ret;
	}
	int solve(int S,int T)
	{
		int ret=0;
		while (bfs(S,T)) ret+=dfs(S,T,inf);
		return ret;
	}
	void send(int _n)
	{
		n=_n,cnte=1;
		memset(head,0,sizeof(head));
	}
	struct node
	{
		int flow,id;
	}b[V];
	int q[V];
	int BFS(int S,int T)
	{
		for (int i=0;i<=n;i++) b[i].flow=0;
		bool flag=1;
		int h=1,t=0;
		b[q[++t]=S]=(node){inf,0};
		while (h<=t&&flag)
		{
			int now=q[h++];
			for (int i=head[now];i;i=e[i].nxt)
			{
				int to=e[i].to,val=e[i].val,tmp=b[to].flow;
				if (!val||tmp>=min(b[now].flow,val)) continue;
				b[to].flow=min(b[now].flow,val);
				b[to].id=i;
				if (tmp) continue;
				q[++t]=to;
				if (to==T)
				{
					flag=0;
					break;
				}
			}
		}
		if (flag) return 0;
		int now=T,flow=b[T].flow;
		while (now!=S)
		{
			int id=b[now].id;
			e[id].val-=flow;
			e[id^1].val+=flow;
			now=e[id^1].to;
		}
		return flow;
	}
	int EK(int S,int T)
	{
		int ret=0;
		while (1)
		{
			int res=BFS(S,T);
			ret+=res;
			if (!res) return ret;
		}
	}
}
int n,m,k,Q,res[1<<K];
void dfs(int S,int k,int sum)
{
	res[S]=sum;
	vector<int>tmp(Flow::cnte+1);
	for (int i=2;i<=Flow::cnte;i++) tmp[i]=Flow::e[i].val;
	for (int i=0;i<k;i++)
	{
		Flow::e[2+i*2].val+=25;
		dfs(S|1<<i,i,sum+Flow::EK(1,n));
		for (int j=2;j<=Flow::cnte;j++) Flow::e[j].val=tmp[j];
	}
}
int w[K],sum[1<<K],Log[1<<K];

signed main()
{
	cin>>n>>m>>k>>Q;
	Flow::send(n);
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		Flow::add(u,v,w);
	}
	int all=(1<<k)-1;
	dfs(0,k,Flow::solve(1,n));
	for (int i=2;i<(1<<k);i++) Log[i]=Log[i/2]+1;
	while (Q--)
	{
		int ans=1e9+7;
		for (int i=0;i<k;i++) cin>>w[i];
		for (int i=1;i<(1<<k);i++) sum[i]=sum[i&(i-1)]+w[Log[i&-i]];
		for (int i=0;i<(1<<k);i++) ans=min(ans,sum[i]+res[all^i]);
		cout<<ans<<endl;
	}
	return 0;
}