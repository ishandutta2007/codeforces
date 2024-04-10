#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> a(n+5),pos(n+5),firstbig(n+5),firstsmall(n+5),len2(n+5);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
	auto print=[&](const vector<int> &vec){for(int i=1;i<=n;i++)cerr<<vec[i]<<' ';cerr<<endl;};

	{
		set<int> s;
		s.insert(0);
		s.insert(n+1);
		for(int i=1;i<=n;i++)
		{
			firstsmall[pos[i]]=*s.lower_bound(pos[i]);
			s.insert(pos[i]);
		}
		s.clear();
		s.insert(0);
		s.insert(n+1);
		for(int i=n;i>=1;i--)
		{
			firstbig[pos[i]]=*s.lower_bound(pos[i]);
			s.insert(pos[i]);
		}
	}
	len2[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i+1]>a[i])
		{
			if(firstsmall[i+1]==firstsmall[i])
				len2[i]=len2[i+1]+1;
			else
				len2[i]=min(len2[i+1]+1,firstsmall[i+1]-i);
		}
		else
		{
			if(firstbig[i+1]==firstbig[i])
				len2[i]=len2[i+1]+1;
			else
				len2[i]=min(len2[i+1]+1,firstbig[i+1]-i);
		}
	}
//	print(firstbig);print(firstsmall);print(len2);
	vector<int> prei(n+5),pred(n+5);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i+1])prei[i]=i,pred[i]=pred[i-1];
		else prei[i]=prei[i-1],pred[i]=i;
	}
//	print(prei);print(pred);
	int dcnt=0,icnt=0,dfirst=0,ifirst=n+1;
	long long ans=0;
	int r=n;
	for(int l=n;l>=1;l--)
	{
		if(a[l]<a[l+1])
		{
			//type i
			if(a[l]>ifirst)
			{
				while(icnt)
				{
					int u=r;r--;
					if(a[u]<a[u+1])icnt--;
					else dcnt--;
				}
			}
			icnt++;
			ifirst=a[l];
		}
		else
		{
			//type d
			if(a[l]<dfirst)
			{
				while(dcnt)
				{
					int u=r;r--;
					if(a[u]<a[u+1])icnt--;
					else dcnt--;
				}
			}
			dcnt++;
			dfirst=a[l];
		}
//		cerr<<l<<' '<<icnt<<' '<<dcnt<<endl;
		int ll=l,rr=r;
		while(ll<rr)
		{
			int mid=(ll+rr+1)/2;
			if(a[mid]<a[mid+1])
			{
				if(l<=pred[mid] and a[pred[mid]]<a[mid])rr=mid-1;
				else ll=mid;
			}
			else
			{
				if(l<=prei[mid] and a[prei[mid]]>a[mid])rr=mid-1;
				else ll=mid;
			}
		}
		ll++;
		int x=a[prei[ll-1]],y=a[pred[ll-1]],t;
		if(ll>n)t=n;
		else
		{
			if(a[ll]>y)
			{
				if(firstsmall[ll]==n+1 or a[firstsmall[ll]]<y)t=ll+len2[ll]-1;
				else t=min(ll+len2[ll]-1,firstsmall[ll]-1);
			}
			else if(a[ll]<x)
			{
				if(firstbig[ll]==n+1 or a[firstbig[ll]]>x)t=ll+len2[ll]-1;
				else t=min(ll+len2[ll]-1,firstbig[ll]-1);
			}
			else
			{
				assert(0);
				return 0;
			}
		}
//		cerr<<"l="<<l<<", "<<"t="<<t<<", "<<x<<' '<<y<<' '<<ll<<' '<<r<<endl;
		ans+=t-l+1;
	}
	cout<<ans<<endl;
	
	return 0;
}