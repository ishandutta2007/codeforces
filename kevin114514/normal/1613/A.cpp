#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define int ll
void die(string S){puts(S.c_str());exit(0);}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int c,d;
        cin>>c>>d;
        int x=min(b,d);
        b-=x;
        d-=x;
        if(b>8)
            cout<<">\n";
        else if(d>8)
            cout<<"<\n";
        else
        {
            
            while(b--)
                a*=10;
            while(d--)
                c*=10;
            if(a>c)
                puts(">");
            else if(a<c)
                puts("<");
            else    puts("=");
        }
    }
	return 0;
}