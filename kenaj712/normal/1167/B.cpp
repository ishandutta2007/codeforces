#include<bits/stdc++.h>
using namespace std;
int tab[10];
pair<int,int> f(int a)
{
    for(int x=1;x<=6;x++)
        for(int y=x+1;y<=6;y++)
            if(tab[x]*tab[y]==a)
                return(make_pair(tab[x],tab[y]));
}
int wsp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
        return b.first;
    else if(a.first==b.second)
        return b.second;
    else
        return a.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int a,b,c,d;
    tab[1]=4;
    tab[2]=8;
    tab[3]=15;
    tab[4]=16;
    tab[5]=23;
    tab[6]=42;
    cout<<"? "<<1<<" "<<2<<'\n';
    fflush(stdout);
    cin>>a;
    cout<<"? "<<1<<" "<<3<<'\n';
    fflush(stdout);
    cin>>b;
    cout<<"? "<<4<<" "<<5<<'\n';
    fflush(stdout);
    cin>>c;
    cout<<"? "<<4<<" "<<6<<'\n';
    fflush(stdout);
    cin>>d;
    cout<<"! ";
    int pom1=wsp(f(a),f(b)),pom2=wsp(f(c),f(d));
    cout<<pom1<<" "<<a/pom1<<" "<<b/pom1<<" "<<pom2<<" "<<c/pom2<<" "<<d/pom2<<'\n';
    fflush(stdout);

	return 0;
}