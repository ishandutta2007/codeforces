#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

long long n, k, a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k >> a >> b;

	if(a > (b+1)*k || b > (a+1)*k)
	{
		cout << "NO\n";
		return 0;
	}

	long long ok=0;
	while(n>0){
		//dbg(n);
		if(a == b){

			for(long long i=a;i>0;i--)
			{
				//dbg("ll");
				if(ok==1)
					cout << "GB";
				else cout << "BG";
			}
			break;
		}
		if(a>b)
		{
//			dbg("ok");
			ok = 1;
			for(long long i=1;i<=k;i++)
			{
				n--;
				cout << 'G';
				a--;
				if(a < b || a==0) break;
			}
			if(b>0)
				cout << 'B', b--, n--;
		}
		else if(b>a){
			ok = -1;
			for(long long i=1;i<=k;i++)
			{
				n--;
				cout << 'B';
				b--;
				if(b<a || b==0) break;
			}
			if(a>0)
				cout << 'G', n--, a--;
		}
	}
cout << '\n';
	return 0;
}