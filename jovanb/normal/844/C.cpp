#include <bits/stdc++.h>

using namespace std;
long br=0;
vector <long long> graf[1000000];
long long niz[100005];
map <long long,long long> indeks;
queue <long long> kju;
long bio[100000];
void dfs(long x){
    if(bio[x]==1)return;
    bio[x]=1;
    for(auto c:graf[x])dfs(c);
    }
void dfs2(long x){
    if(bio[x]==1)return;
    bio[x]=1;
    br++;
    kju.push(x);
    for(auto c:graf[x])dfs2(c);
    }
int main()
{
    long n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
        niz[i]+=1000000000;
        indeks[niz[i]]=i;
    }
    sort(niz,niz+n);
    for(i=0;i<n;i++){
        if(indeks[niz[i]]!=i){
            graf[i].push_back(indeks[niz[i]]);

        }
    }
    for(i=0;i<n;i++){
        if(bio[i]==0){
            br++;
            dfs(i);
        }
    }
    cout<<br;
    for(i=0;i<n;i++)bio[i]=0;
    for(i=0;i<n;i++){
        br=0;
        if(bio[i]==0){
            dfs2(i);
            cout<<endl<<br;
            while(kju.empty()==false){
                cout<<" "<<kju.front()+1;
                kju.pop();
            }
        }
    }
    return 0;
}