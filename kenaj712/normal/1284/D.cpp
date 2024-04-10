#include<bits/stdc++.h>
using namespace std;
int tab[100005][4];
vector<int> tab_dodaj_min[500005];
vector<int> tab_dodaj_max[500005];
vector<int> tab_wywal_min[500005];
vector<int> tab_wywal_max[500005];
set<int> s;
multiset<int> s_min;
multiset<int> s_max;
vector<int> v;
int tree_max[2000005];
int tree_min[2000005];
int pot=(1<<19);
void ins_max(int a,int b)
{
    int pom=a+pot;
    while(pom!=0)
    {
        tree_max[pom]=max(tree_max[pom],b);
        pom/=2;
    }
}
int check_max(int a,int b)
{
    int l=a+pot,r=b+pot;
    int war=tree_max[l];
    if(l!=r)
        war=max(war,tree_max[r]);
    while(l/2!=r/2)
    {
        if(l%2==0)
            war=max(war,tree_max[l+1]);
        if(r%2==1)
            war=max(war,tree_max[r-1]);
        l/=2;
        r/=2;
    }
    return war;
}
void ins_min(int a,int b)
{
    int pom=a+pot;
    while(pom!=0)
    {
        tree_min[pom]=min(tree_min[pom],b);
        pom/=2;
    }
}
int check_min(int a,int b)
{
    int l=a+pot,r=b+pot;
    int war=tree_min[l];
    if(l!=r)
        war=min(war,tree_min[r]);
    while(l/2!=r/2)
    {
        if(l%2==0)
            war=min(war,tree_min[l+1]);
        if(r%2==1)
            war=min(war,tree_min[r-1]);
        l/=2;
        r/=2;
    }
    return war;
}
void przenumeruj(int a)
{
    for(auto x:s)
        v.push_back(x);
    for(int x=0;x<a;x++)
        for(int y=0;y<4;y++)
            tab[x][y]=lower_bound(v.begin(),v.end(),tab[x][y])-v.begin();
}
void pre()
{
    for(int x=0;x<=2000002;x++)
    {
        tree_min[x]=1e9;
        tree_max[x]=-1e9;
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	int a;
	cin>>a;
    for(int x=0;x<a;x++)
        for(int y=0;y<4;y++)
        {
            cin>>tab[x][y];
            s.insert(tab[x][y]);
        }
    przenumeruj(a);
    s.clear();
    for(int x=0;x<a;x++)
    {
        tab_dodaj_min[tab[x][0]].push_back(tab[x][3]);
        tab_dodaj_max[tab[x][0]].push_back(tab[x][2]);
        tab_wywal_min[tab[x][1]].push_back(tab[x][3]);
        tab_wywal_max[tab[x][1]].push_back(tab[x][2]);
    }
    for(int x=0;x<=4e5+5;x++)
    {
        for(auto y:tab_dodaj_min[x])
            s_min.insert(y);
        for(auto y:tab_dodaj_max[x])
            s_max.insert(-y);
        if(s_min.empty()==false)
            ins_min(x,*s_min.begin());
        if(s_max.empty()==false)
            ins_max(x,-*s_max.begin());
        for(auto y:tab_wywal_min[x])
            s_min.erase(s_min.lower_bound(y));
        for(auto y:tab_wywal_max[x])
            s_max.erase(s_max.lower_bound(-y));
        tab_dodaj_min[x].resize(0);
        tab_dodaj_max[x].resize(0);
        tab_wywal_min[x].resize(0);
        tab_wywal_max[x].resize(0);
    }
    for(int x=0;x<a;x++)
    {
        if(check_min(tab[x][0],tab[x][1])<tab[x][2]||check_max(tab[x][0],tab[x][1])>tab[x][3])
        {
            cout<<"NO";
            return 0;
        }
    }
    pre();
    for(int x=0;x<a;x++)
    {
        swap(tab[x][0],tab[x][2]);
        swap(tab[x][1],tab[x][3]);
        tab_dodaj_min[tab[x][0]].push_back(tab[x][3]);
        tab_dodaj_max[tab[x][0]].push_back(tab[x][2]);
        tab_wywal_min[tab[x][1]].push_back(tab[x][3]);
        tab_wywal_max[tab[x][1]].push_back(tab[x][2]);
    }
    for(int x=0;x<=4e5+5;x++)
    {
        for(auto y:tab_dodaj_min[x])
            s_min.insert(y);
        for(auto y:tab_dodaj_max[x])
            s_max.insert(-y);
        if(s_min.empty()==false)
            ins_min(x,*s_min.begin());
        if(s_max.empty()==false)
            ins_max(x,-*s_max.begin());
        for(auto y:tab_wywal_min[x])
            s_min.erase(s_min.lower_bound(y));
        for(auto y:tab_wywal_max[x])
            s_max.erase(s_max.lower_bound(-y));
    }
    for(int x=0;x<a;x++)
    {
        if(check_min(tab[x][0],tab[x][1])<tab[x][2]||check_max(tab[x][0],tab[x][1])>tab[x][3])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}