#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int ans,n,m;
char c[100][100];
set<char>s;

bool ok(char a)
{
    if(s.find(a)!=s.end())
        return true;
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>c[i][j];
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++)
        {
            s.clear();
            s.insert(c[i][j]);
            s.insert(c[i+1][j]);
            s.insert(c[i][j+1]);
            s.insert(c[i+1][j+1]);
            if(ok('f') && ok('a') && ok('c') && ok('e'))
                ans++;
        }
    cout<<ans<<endl;
}