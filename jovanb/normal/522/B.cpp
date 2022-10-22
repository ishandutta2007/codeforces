#include <bits/stdc++.h>
using namespace std;
long w[200000],h[200000];
priority_queue <long> pq;
int main(){
    long n,b=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>w[i]>>h[i];
        pq.push(h[i]);
        b+=w[i];
    }
    for(i=0;i<n;i++){
        if(h[i]==pq.top()){
            pq.pop();
            cout<<(b-w[i])*pq.top()<<" ";
            pq.push(h[i]);
        }
        else cout<<(b-w[i])*pq.top()<<" ";
    }
    return 0;
}