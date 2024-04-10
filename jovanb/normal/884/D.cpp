#include <bits/stdc++.h>

using namespace std;
priority_queue <long long> q;
int main()
{
    long n,i;
    long long a,b,c,zbir=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        q.push(-a);
    }
    while(q.size()>1){
        if(q.size()%2!=0){
            a=q.top();
            q.pop();
            b=q.top();
            q.pop();
            c=q.top();
            q.pop();
            zbir+=(-(a+b+c));
            q.push(a+b+c);
        }
        else{
            a=q.top();
            q.pop();
            b=q.top();
            q.pop();
            zbir+=(-(a+b));
            q.push(a+b);
        }
    }
    cout<<zbir;
    return 0;
}