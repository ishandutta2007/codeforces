#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <pair<int,int> > t,kar;
int n,k;

int getmin()
{
	if (t.size()==0) return kar[kar.size()-1].first;
	if (kar.size()==0) return t[t.size()-1].first;
	if (t[t.size()-1].first<kar[kar.size()-1].first) return t[t.size()-1].first;
	return kar[kar.size()-1].first;
}

int main()
{
	t.resize(0);
	kar.resize(0);
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		int C,T;
		scanf("%d%d",&C,&T);
		if (T==1) t.push_back(make_pair(C,i+1));
		else kar.push_back(make_pair(C,i+1));
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	sort(kar.begin(),kar.end());
	reverse(kar.begin(),kar.end());
	double ans=0;
	if (t.size()<k)
	{
		for (int i=0;i<t.size();i++) ans+=t[i].first;
		ans=ans/2;
		for (int i=0;i<kar.size();i++) ans+=kar[i].first;
		printf("%.1f\n",ans);
// 		cout << ans << endl;
		for (int i=0;i<t.size();i++) cout << 1 << ' ' << t[i].second << endl;
		for (int i=t.size();i<k-1;i++) cout << 1 << ' ' << kar[i-t.size()].second << endl;
		cout << kar.size()-(k-t.size()-1);
		for (int i=k-t.size()-1;i<kar.size();i++) cout << ' ' << kar[i].second;
		cout << endl;
		return 0;
	}
	for (int i=0;i<k-1;i++) ans+=t[i].first;
	ans=ans/2;
	for (int i=k-1;i<t.size();i++) ans+=t[i].first;
	for (int i=0;i<kar.size();i++) ans+=kar[i].first;
	ans-=(getmin()/2.0);
// 	if (t[t.size()-1].first<kar[kar.size()-1].first) ans-=(t[t.size()-1].first/2.0);
// 	else ans-=(kar[kar.size()-1].first/2.0);
	printf("%.1f\n",ans);
// 	cout << ans << endl;
	for (int i=0;i<k-1;i++) cout << 1 << ' ' << t[i].second << endl;
	cout << n-(k-1);
	for (int i=k-1;i<t.size();i++) cout << ' ' << t[i].second;
	for (int i=0;i<kar.size();i++) cout << ' ' << kar[i].second;
	return 0;
}