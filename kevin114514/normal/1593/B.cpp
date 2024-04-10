#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int ans=s.length();
		for(int i=0;i<s.length();i++)
			for(int j=i+1;j<s.length();j++)
				if((10*(s[i]^48)+(s[j]^48))%25==0)
					ans=min(ans,(int)(s.length()-i-2));
		cout<<ans<<endl;
	}
	return 0;
}