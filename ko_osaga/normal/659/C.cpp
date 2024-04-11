#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main(){
int n,m;
scanf("%d%d",&n,&m);
set<int> s;
vector<int> v;
for(int i=0;i<n;i++){
int t;
scanf("%d",&t);
s.insert(t);
}
for(int i=1;i<=300000;i++){
if(s.find(i) == s.end() && i<=m){
v.push_back(i);
m-=i;
}}

printf("%d\n",v.size());
for(auto i:v) printf("%d ",i);
}