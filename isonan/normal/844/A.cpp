#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[1001];
int k,ans;
bool vis[26];
int main(){
    scanf("%s",str);
    int len=0;
    for(int i=0;str[i];i++){
        len++;
        if(!vis[str[i]-'a'])vis[str[i]-'a']=1,ans++;
    }
    scanf("%d",&k);
    if(k>len)puts("impossible");
    else printf("%d\n",max(0,k-ans));
}