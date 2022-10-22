#include <bits/stdc++.h>

using namespace std;
queue <long long> q;
int main()
{
    long long n,a,zbir,i,b;
    cin>>n;
    a=n-100;
    if(a<0)a=0;
    for(i=a;i<n;i++){
        b=i;
        zbir=0;
        while(b>0){
            zbir+=b%10;
            b/=10;
        }
        if(zbir+i==n)q.push(i);
    }
    cout<<q.size()<<endl;
    while(q.empty()==false){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}