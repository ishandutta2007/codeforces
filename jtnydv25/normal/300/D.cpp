
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
const int mod = 7340033;

void print(vi& v)
{
	for(int i = 0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
void mul(vi& A, vi& B, int k)
{
	vi C(A.size()+B.size()-1,0);
	for(int i = 0;i<A.size();i++)
		for(int j = 0;(j<B.size()) && (j+i <= k);j++){
			C[i+j] += (A[i]*1ll*B[j])%mod;
			if(C[i+j]>=mod)
				C[i+j] -= mod;
		}
		C.resize(min((int)C.size(),k+1));
		A = C;
}

void pw4(vi& A, int k)
{
	mul(A,A,k);
	mul(A,A,k);
}
vi V[32];
int getele(vi& v, int k)
{
	if(v.size()<=k)
		return 0;
	return v[k];
}
int ans(int n, int k)
{
	int x = 0;
	while((n & 1)&&(n!=1))
	{
		x++;
		n>>=1;
	}
	return getele(V[x+1],k);
}
int main()
{
	vi v1;
	vi v;
	v.pb(1);
	v1.pb(0);
	v1.pb(1);//v1 = x
	for(int i = 1;i<32;i++)
	{
		V[i] = v;
		pw4(v,1000);
		mul(v,v1,1000);
		assert(v[0] == 0);
		v[0] = 1;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		cout<<ans(n,k)<<"\n";
	}
}