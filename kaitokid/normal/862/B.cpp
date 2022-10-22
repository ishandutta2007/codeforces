#include <bits/stdc++.h>
using namespace std;

vector<int> a[100009];
long long an;
void d(int pr,int x,bool bl)
{if(bl)an++;
for(int i=0;i<a[x].size();i++){if(a[x][i]!=pr)d(x,a[x][i],1-bl);}


}

int main(){
ios::sync_with_stdio(0);
long long n,x,y,p1,p2;
cin>>n;
for(int i=1;i<n;i++)
{cin>>x>>y;
a[x].push_back(y);
a[y].push_back(x);}
int p=0;
d(-1,x,true);
long long an2=n-an;
cout<<(an*an2)-n+1;
//cout<<an<<endl<<an2;


return 0;}