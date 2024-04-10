#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back

void findvec(int k, int sm , int n,vi& v)
{
	if(k == 0)
		return;
	if(k == sm)
	{
		for(int i = 1;i<=k;i++)
			v.pb(1);
		return;
	}
	if(k == 1){
		assert(sm<=n && sm >= 1);
		v.pb(sm);
		return;	
	}
	int mx = min(n, sm - (k-1));
	v.pb(mx);
	findvec(k-1,sm-mx,n,v);
}
int main()
{
	int n,np=0,nm=0;
	char x = '?';
	char a[1000];
	int sz = 0;
	while(x != '='){
		cin >> x;
		a[sz++] = x;
		if(x == '+')
			np++;
		if(x=='-')
			nm++;
	}
	cin>>n;
	np++;
	vi p,m;
	// sum_{i=1}^{np} a_i - sum_{j=1}^{nm}b_i = n
	int mxv = np * n - nm * 1, mnv = np * 1 - nm * n;
	if(mxv < n || mnv > n){
		cout<<"Impossible\n";
		return 0;
	}
	for(int sm = np;sm <= np*n;sm++)
	{
		int sm2 = sm - n;
		if(sm2 >= nm && sm2 <= nm * n)
		{
			cout<<"Possible\n";
			findvec(np,sm,n,p);
			findvec(nm,sm2,n,m);
			cout<<p.back()<<" ";
			p.pop_back();
			char prevsign;
			for(int i = 1;i<sz;i++)
			{
				char x = a[i];
				if(x == '='){
					cout<<'='<<" ";
					break;
				}
				if(x == '?')
				{
					if(prevsign == '+')
					{
						cout<<p.back()<<" ";
						p.pop_back();
					}
					else
					{
						cout<<m.back()<<" ";
						m.pop_back();
					}
				}
				else
				{
					if(x == '+'){
						prevsign = '+';
						cout<<"+ ";
					}
					else{
						prevsign = '-';
						cout<<"- ";
					}
				}
			}
			cout<<n<<endl;
			return 0;
		}
	}
}