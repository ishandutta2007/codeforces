#include <bits/stdc++.h>
using namespace std;
long niz[200005];
long p[200005];
bool vec[200005];
priority_queue <long> q;
int main()
{
    long n,br=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
        p[niz[i]]++;
    }
    for(i=1;i<=n;i++){
        if(p[i]==0){q.push(-i);br++;}
    }
    for(i=0;i<n;i++){
    }
    for(i=0;i<n;i++){

        if(p[niz[i]]>1){
            if(-(q.top())<niz[i] || vec[niz[i]]==true){
                    p[niz[i]]--;
                    niz[i]=-(q.top());

                    q.pop();

            }
            else vec[niz[i]]=true;
        }
    }
    cout<<br<<endl;
    for(i=0;i<n;i++)cout<<niz[i]<<" ";
    return 0;
}