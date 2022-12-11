#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
char ch[110000];
int n,m;
set<int>L,R;
vector<int>go;
int getrem(){
    set<int>::iterator k=L.begin();
    int ans=n+1;
    if (k!=L.end()) ans=min(ans,(*k));
    k=R.begin();
    if (k!=R.end()) ans=min(ans,(*k));
    return ans;
}
int main(){
    scanf("%s",ch+1); n=strlen(ch+1);
    int sizeL=0,sizeR=0;
    for (int i=1;i<=n;i++) if (ch[i]=='L') sizeL++; else sizeR++;
    if (sizeL<sizeR||(sizeL==sizeR&&ch[1]=='R')){
        for (int i=1;i<=n;i++) if (ch[i]=='L') ch[i]='R'; else ch[i]='L';
        swap(sizeL,sizeR);
    }
//  for (int i=1;i<=n;i++) putchar(ch[i]); cout<<endl;
    for (int i=1;i<=n;i++) if (ch[i]=='L') L.insert(i);
    for (int i=1;i<=n;i++) if (ch[i]=='R') R.insert(i);
    set<int>::iterator k=L.begin(); int now=(*k),ans=0,pd=0;
    L.erase(k); 
//  for (int i=1;i<=n;i++) putchar(ch[i]); cout<<endl;
    for (int i=1;i<n;i++){
        go.push_back(now); //cout<<now<<" "<<pd<<endl;
        if (pd==0){
            k=R.lower_bound(now);
            if (k==R.end()){
                k=R.begin(); ans++; pd=1; now=(*k); R.erase(k); continue;
            }
            int ne=(*k);
            if (L.lower_bound(ne)==L.end()){
                int k1=getrem();// cout<<k1<<" "<<now<<" "<<ch[k1]<<" "<<ch[now]<<endl;
                if (k1<now&&ch[k1]!=ch[now]){
                    now=k1; ans++; pd=1; R.erase(k1); continue;
                }
            }
            now=(*k); R.erase(*k); pd=1;
        } else {
            k=L.lower_bound(now);
            if (k==L.end()){
            //  cout<<L.size()<<endl;
                k=L.begin(); ans++; pd=0; now=(*k); L.erase(k); continue;
            }
            int ne=(*k);// cout<<ne<<endl;
            if (R.lower_bound(ne)==R.end()){
                int k1=getrem();// cout<<k1<<" "<<now<<" "<<ch[k1]<<" "<<ch[now]<<endl;
                if (k1<now&&ch[k1]!=ch[now]){
                    now=k1; ans++; pd=0; L.erase(k1); continue;
                }
            }
            now=(*k); L.erase(*k); pd=0;
        } 
    }
    go.push_back(now); printf("%d\n",ans);
    for (int i=0;i<go.size();i++) printf("%d ",go[i]);
    putchar('\n');
    return 0;
}