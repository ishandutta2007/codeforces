#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6+10;
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
bool isp[maxn];
void print(vi& v)
{
	cout<<v.size()<<endl;
	for(int i = 0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";

}
void pre()
{
	memset(isp,0,sizeof isp);
	for(int i = 2;i*i<maxn;i++)
		if(!isp[i])
			for(int j = i*i;j<maxn;j+=i)
				isp[j]= 1;			
}
bool isprime(int n)
{
	if(n<2 || isp[n])
		return 0;
	return 1;
}
int main()
{
	pre();
	//cout<<isp[2]<<" "<<isp[5]<<endl;
	int n;
	cin>>n;
	int n1 = 0;
	int a[n+10];
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(a[i] == 1)
			n1++;
	}
	// cout<<n1<<endl;
	if(n1 >= 2)
	{
		vi v(n1,1);
		pair<int,int> pr = mp(0,0);
		int flg1 = 0,flg2= 0;
		for(int i = 0;i<n;i++){
			if(a[i]!=1 && isprime(a[i]+1)){
				flg1 = a[i];
				for(int j =i+1;j<n;j++){
					// cout<<a[i]<<" "<<a[j]<<"\n";
					if(a[j] != 1 && isprime(a[j]+1))
						if(isprime(a[i]+a[j]))
							pr = mp(a[i],a[j]);
				}
			}
		}
		if(pr.F != 0)
		{
			v.pb(pr.F);
			v.pb(pr.S);
			print(v);
			return 0;
		}
		if(flg1 != 0)
		{
			v.pb(flg1);
			print(v);
			return 0;
		}
		print(v);
		return 0;
	}
	pii pr = mp(0,0);
	for(int i = 0;i<n;i++)
		for(int j = i+1;j<n;j++)
			if(isprime(a[i]+a[j]))
			{
				cout<<2<<endl;
				cout<<a[i]<<" "<<a[j]<<endl;
				return 0;
			}
	cout<<1<<"\n"<<a[0];		
}