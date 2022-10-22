
 #include <bits/stdc++.h>

using namespace std;

long long niz[300000],problem[300000];
unordered_map <long long, long long> ind;
int main(){
    int n,mark=1,i;
    cin>>n;
    long long max1=-10,max2=-19,maxi=0,br=0;
    for(i=1;i<=n;i++)cin>>niz[i];
    for(i=1;i<=n;i++){
        if(ind[niz[i]]==0)ind[niz[i]]=i;
        if(niz[i]>max1){
            max2=max1;
            max1=niz[i];
            problem[ind[niz[i]]]--;
        }
        else if(niz[i]>max2){
            max2=niz[i];
            problem[ind[max1]]++;
        }
    }
    for(i=1;i<=n;i++){
        if(problem[i]>problem[mark] || (problem[i]==problem[mark] && niz[i]<niz[mark]))mark=i;
    }
    cout<<niz[mark];
    return 0;
}