#include<bits/stdc++.h>
using namespace std;
bool ok1[1005][1005];
bool ok2[1005][1005];
int row[1005];
int column[1005];
const int mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    long long act=1;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>row[x];
    for(int x=0;x<b;x++)
        cin>>column[x];
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
        {
            if(y<row[x]||x<column[y])
                ok1[x][y]=true;
            if(y==row[x]||x==column[y])
                ok2[x][y]=true;
        }
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
        {
            if(ok1[x][y]==true)
            {
                if(ok2[x][y]==true)
                    act=0;
            }
            else
            {
                if(ok2[x][y]==false)
                    act=(act*2)%mod;
            }
        }
    cout<<act;
	return 0;
}