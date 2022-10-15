#include <iostream>
using namespace std;

int main()
{
    int n;
    string s,t;
	cin>>n>>s>>t;

	int sum=0,a[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]!=t[i-1])
		{
			if(s[i-1]=='1') a[i]=-1;
			else a[i]=1;
		}
		sum+=a[i];
	}

	if(sum!=0) { cout<<-1; return 0; }

	int cur1=0,cur2=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cur1+=a[i];
		cur2-=a[i];
		ans=max(ans,cur1);
		ans=max(ans,cur2);
		if(cur1<0) cur1=0;
		if(cur2<0) cur2=0;
	}

	cout<<ans<<endl;
	return 0;
}