/*
the most important thing:
think twice,code once
*/
#include<bits/stdc++.h>
using namespace std;
/* --------------- fast io --------------- */ // begin
namespace _ {
	const int _________= 1 << 16;
	char buf[_________],*S,*T;
	inline char getchar() {
		if(S==T) {
			T=(S=buf)+
			  fread(buf,1,_________,stdin);
			if(S==T)return'\n';
		}
		return *S++;
	}
} // namespace _
namespace __ {
	const int _________= 1 << 16;
	char buf[_________],*S=buf,*T=buf+_________;
	inline void flush() {
		fwrite(buf,1,S-buf,stdout);
		S=buf;
	}
	inline void putchar(char c) {
		*S++=c;
		if(S==T)flush();
	}
	struct NTR {
		~NTR() {
			flush();
		}
	} ztr;
} // namespace __
#ifdef ONLINE_JUDGE
#define getchar _::getchar
#define putchar __::putchar
#endif
namespace ___ {
	struct __________ {
		template<typename T>__________&operator>>(T&x) {
			char c=getchar();
			short f=1;
			while(c<'0'||c>'9') {
				if(c=='-')f*=-1;
				c=getchar();
			}
			x=0;
			while(c>='0'&&c<='9') {
				x=(x<<1)+(x<<3)+(c^48);
				c=getchar();
			}
			x*=f;
			return *this;
		}
		__________&operator>>(double&x) {
			char c=getchar();
			short f=1,s=0;
			x=0;
			double t=0;
			while((c<'0'||c>'9')&&c!='-'&&c!='.') {
				if(c=='-')f*=-1;
				c=getchar();
			}
			while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
			if(c=='.')c=getchar();
			else return x*=f,*this;
			while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
			while(s--)t/=10.0;
			x=(x+t)*f;
			return*this;
		}
		__________&operator>>(long double&x) {
			char c=getchar();
			short f=1,s=0;
			x=0;
			long double t=0;
			while((c<'0'||c>'9')&&c!='-'&&c!='.') {
				if(c=='-')f*=-1;
				c=getchar();
			}
			while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
			if(c=='.')c=getchar();
			else return x*=f,*this;
			while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
			while(s--)t/=10.0;
			x=(x+t)*f;
			return*this;
		}
		__________&operator>>(__float128&x) {
			char c=getchar();
			short f=1,s=0;
			x=0;
			__float128 t=0;
			while((c<'0'||c>'9')&&c!='-'&&c!='.') {
				if(c=='-')f*=-1;
				c=getchar();
			}
			while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
			if(c=='.')c=getchar();
			else return x*=f,*this;
			while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
			while(s--)t/=10.0;
			x=(x+t)*f;
			return*this;
		}
		__________&operator>>(char&c) {
			c=getchar();
			while(c=='\n'||c==' '||c=='\r')c=getchar();
			return *this;
		}
		__________&operator>>(char*str) {
			int len=0;
			char c=getchar();
			while(c=='\n'||c==' '||c=='\r')c=getchar();
			while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();
			str[len]='\0';
			return*this;
		}
		__________&operator>>(string&str) {
			str.clear();
			char c=getchar();
			while(c=='\n'||c==' '||c=='\r')c=getchar();
			while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();
			return*this;
		}
		__________() {}
	} cin;
	const char endl='\n';
	struct ___________ {
		const int ____=6;
		typedef int ________;
		template<typename T>___________&operator<<(T x) {
			if(x==0)return putchar('0'),*this;
			if(x<0)putchar('-'),x=-x;
			static int _____[45];
			int _______=0;
			while(x)_____[++_______]=x%10,x/=10;
			while(_______)putchar(_____[_______]+'0'),--_______;
			return*this;
		}
		___________&operator<<(double x) {
			if(x<0)putchar('-'),x=-x;
			________ _=x;
			x-=(double)_;
			static int _____[45];
			int _______=0;
			while(_)_____[++_______]=_%10,_/=10;
			if(!_______)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			putchar('.');
			for(int i=0; i<____; i++)x*=10;
			_=x;
			while(_)_____[++_______]=_%10,_/=10;
			for(int i=0; i<____-_______; i++)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			return*this;
		}
		___________&operator<<(long double x) {
			if(x<0)putchar('-'),x=-x;
			________ _=x;
			x-=(long double)_;
			static int _____[45];
			int _______=0;
			while(_)_____[++_______]=_%10,_/=10;
			if(!_______)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			putchar('.');
			for(int i=0; i<____; i++)x*=10;
			_=x;
			while(_)_____[++_______]=_%10,_/=10;
			for(int i=0; i<____-_______; i++)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			return*this;
		}
		___________&operator<<(__float128 x) {
			if(x<0)putchar('-'),x=-x;
			________ _=x;
			x-=(__float128)_;
			static int _____[45];
			int _______=0;
			while(_)_____[++_______]=_%10,_/=10;
			if(!_______)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			putchar('.');
			for(int i=0; i<____; i++)x*=10;
			_=x;
			while(_)_____[++_______]=_%10,_/=10;
			for(int i=0; i<____-_______; i++)putchar('0');
			while(_______)putchar(_____[_______]+'0'),--_______;
			return*this;
		}
		___________&operator<<(char c) {
			putchar(c);
			return*this;
		}
		___________& operator<<(char*str) {
			int cur=0;
			while(str[cur])putchar(str[cur++]);
			return *this;
		}
		___________&operator<<(const char*str) {
			int cur=0;
			while(str[cur])putchar(str[cur++]);
			return*this;
		}
		___________&operator<<(string str) {
			int st=0,ed=str.size();
			while(st<ed)putchar(str[st++]);
			return*this;
		}
		___________() {}
	} cout;
} // namespace ___
#define cin ___ :: cin
#define cout ___ :: cout
#define endl ___ :: endl
/* --------------- fast io --------------- */ // end
long long pow(long long x,long long y,long long p) {
	long long ans=1;
	for (; y; y>>=1,x=x*x % p)
		if (y&1) ans=ans*x % p;
	return ans;
}
long long gcd(long long x,long long y) {
	if (y==0) return x;
	long long ans=gcd(y,x % y);
	return ans;
}
long long Testing,n,ans,x,i;
int main() {
//	freopen("testdata.in","r",stdin);
	cin>>Testing;
	for (; Testing; Testing--) {
		    cin>>n;ans=0;
		    for (i=1;i<=9;i++)
		        {
		        	x=i;
		        	while (x<=n)
		        	    {
		        	    	 ans++;x=x*10+i;
						}
				}
			cout<<ans<<endl;
	}
	return 0;
}