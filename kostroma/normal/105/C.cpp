#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve ();
	return 0;
}
//caution: is int really int?
//#define int li
map <string, string> artef;
struct or
{
	string name, clas; int atk, def, res, size;
	vector < pair <int, string> > arts;
	or (){}
	void scan () 	{	cin>>name>>clas>>atk>>def>>res>>size;	}
	int ataka () 
	{
		int resatk=atk;
		for ( int i=0; i<arts.size(); i++ )
			if ( artef[arts[i].second][0]=='g' )
				resatk+=arts[i].first;
		return resatk;
	}
	int defense ()
	{
		int resdef=def;
		for ( int i=0; i<arts.size(); i++ )
			if ( artef[arts[i].second][0]=='s' )
				resdef+=arts[i].first;
		return resdef;
	}
	int result ()
	{
		int resres=res;
		for ( int i=0; i<arts.size(); i++ )
			if ( artef[arts[i].second][0]=='p' )
				resres+=arts[i].first;
		return resres;
	}
	void print () 
	{
		cout<<name<<' ';
		cout<<arts.size();
		for ( int i=0; i<arts.size(); i++ )
			cout<<' '<<arts[i].second;
		cout<<endl;
	}
};
map <string, or> part;
typedef map <string, or>::iterator iter;
map <string, int> artefakt;
int n, k;
// atk			def			 res
// weapon		armor		orb
//gladiator		sentry		physician
vector <pair <int, string> > art[5]; // 0 - atk, 1- def, 2 - res
vector <or> party[5]; // 0 - atk, 1- def, 2 - res
map <string, bool> zanart;
void readdata ()
{
	cin>>n;
	for ( int i=0; i<n; i++ )
	{
		or u;
		u.scan();
		part[u.name]=u;
	}
	cin>>k;
	for ( int i=0; i<k; i++ )
	{
		int bonus;
		string name, type, home;
		cin>>name>>type>>bonus>>home;
		artefakt[name]=bonus;
		zanart[name]=false;
		artef[name]=type;
		//cout<<name<<' '<<type<<' '<<home<<' '<<bonus<<endl;
		part[home].arts.pb(mp ( bonus, name ) );
		if (type[0]=='g')
			art[0].pb ( mp (bonus, name) );
		if (type[0]=='s')
			art[1].pb ( mp (bonus, name) );
		if (type[0]=='p')
			art[2].pb ( mp (bonus, name) );
	}
	for ( iter i=part.begin(); i!=part.end(); i++ )
	{
		or u=i->second;
		if ( u.clas[0]=='w' )
			party[0].pb (u);
		if ( u.clas[0]=='a' )
			party[1].pb (u);
		if ( u.clas[0]=='o' )
			party[2].pb (u);
	}
}
void doshit ()
{
	int j=0;
		for ( int i=0; i<party[0].size(); i++ )
		{
			if ( party[0][i].ataka()>party[0][j].ataka() )
				j=i;
		}
		party[0][j].print();
		j=0;
		for ( int i=0; i<party[1].size(); i++ )
		{
			if ( party[1][i].defense()>party[1][j].defense() )
				j=i;
		}
		party[1][j].print();
		j=0;
		for ( int i=0; i<party[2].size(); i++ )
		{
			if ( party[2][i].result()>party[2][j].result() )
				j=i;
		}
		party[2][j].print();
}
int pref[5][2000];
void fill ()
{
	for ( int i=0; i<3; i++ )
	{
	sort (art[i].begin(), art[i].end());
	reverse (art[i].begin(), art[i].end());
	if (art[i].size()!=0)
		pref[i][0]=art[i][0].first;
	for ( int j=1; j<art[i].size(); j++ )
		pref[i][j]=pref[i][j-1]+art[i][j].first;
	}
}
string better[5];
void findbest ()
{
	for ( int cur=0; cur<3; cur++ )
	{
		int best=0, bestsum=0, numart=0;
		for ( int i=0; i<party[cur].size(); i++ )
		{
			int mest=party[cur][i].size;
			int big;
			if (cur==0)
				big=party[cur][i].atk;
			if (cur==1)
				big=party[cur][i].def;
			if (cur==2)
				big=party[cur][i].res;
			if (art[cur].size()!=0)
			big+=pref[cur][min(mest, (int)art[cur].size())-1];
			if (big>bestsum)
			{
				bestsum=big;
				best=i;
				numart=min(mest, (int)art[cur].size());
			}
		}
		or krut=party[cur][best];
		better[cur]=krut.name;
		for ( int i=0; i<numart; i++ )
		{
			part[krut.name].arts.pb ( art[cur][i] );
			party[cur][best].arts.pb (art[cur][i]);
			zanart[art[cur][i].second]=true;
		}
	}
}

void solve ()
{
	readdata();		bool f=true;
	for ( iter i=part.begin(); i!=part.end(); i++ )	{	or val=i->second;		if ( val.arts.size()<val.size )	{	f=false;	break;	}		}
	if ( f )	{	doshit();	return;	}
	for (iter i=part.begin(); i!=part.end(); i++)		i->second.arts.resize(0);
	fill();
	findbest();
	for ( int cur=0; cur<3; cur++ )
	{
		string curbest=better[cur];
		if ( part[curbest].size>part[curbest].arts.size() )
		{
			for ( map <string, bool>::iterator i=zanart.begin(); i!=zanart.end(); i++ )
				if ( i->second==false )
				{
					i->second=true;
					part[curbest].arts.pb ( mp ( artefakt[i->first], i->first ) );
					if ( part[curbest].size==part[curbest].arts.size() )
						break;
				}
		}
		part[curbest].print();
	}
}