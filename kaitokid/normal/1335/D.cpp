#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s[10];
void g(int i,int j)
{
    if(s[i][j]=='9'){s[i][j]='1';return;}
    s[i][j]++;
}
int main()
{
    ios::sync_with_stdio(0);
int t,n;
int x,a,b;
cin>>t;
while(t--)
{

for(int i=0;i<9;i++)cin>>s[i];

g(0,0);
g(1,3);
g(2,6);
g(3,1);
g(4,4);
g(5,7);
g(6,2);
g(7,5);
g(8,8);
for(int i=0;i<9;i++)cout<<s[i]<<endl;

}
    return 0;
}