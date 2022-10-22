#include <bits/stdc++.h>

using namespace std;
queue <int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int h1,a1,c1,h2,a2;
    cin>>h1>>a1>>c1>>h2>>a2;
    while(h2>0){
        if(h1<=a2 && h2>a1){h1+=c1;q.push(1);}
        else {h2-=a1;q.push(2);}
        h1-=a2;
    }
    cout<<q.size()<<endl;
    while(!q.empty()){
        if(q.front()==1)cout<<"HEAL\n";
        else cout<<"STRIKE\n";
        q.pop();
    }
    return 0;
}