#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define dmg first.first
#define pow first.second
#define ind second
void die(string S){puts(S.c_str());exit(0);}
vector<pair<int,int> > usage;
int N,mx,health,regen;
int damage;
bool USED[1010];
pair<pair<int,int>,int> scroll[1010];//((dmg,pow),i)
int t=0;
inline bool cast(int num)//pow*mx>=health*100
{
	if(USED[num])
		return true;
	if(scroll[num].pow*mx>=health*100)
	{
		damage+=scroll[num].dmg;
		usage.pb(mp(t,scroll[num].ind));
		return false;
	}
	return true;
}
inline bool use()
{
	int num=0;
	while(num<N&&cast(num))
		num++;
	if(num==N)
		return false;
	USED[num]=1;
	return true;
}
inline void hit()
{
	health-=damage;
	health+=regen;
	health=min(health,mx);
}
void Die()
{
	puts("YES");
	cout<<t<<" "<<sz(usage)<<endl;
	for(int i=0;i<sz(usage);i++)
		cout<<usage[i].first<<" "<<usage[i].second<<endl;
	exit(0);
}
inline void op()
{
	hit();
	if(health<=0)
		Die();
	bool used=use();
	if(damage<=regen&&!used)
		die("NO");
}
int main()
{
	cin>>N>>mx>>regen;
	health=mx;
	for(int i=0;i<N;i++)
	{
		cin>>scroll[i].pow>>scroll[i].dmg;
		scroll[i].ind=i+1;
	}
	sort(scroll,scroll+N);
	reverse(scroll,scroll+N);
	if(!use())
		die("NO");
	while(++t)
		op();
	return 0;
}