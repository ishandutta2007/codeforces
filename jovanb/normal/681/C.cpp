#include <bits/stdc++.h>
using namespace std;

priority_queue <long> pq;
vector <long> brojevi;
vector <string> stringovi;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,x,i;
    string str;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>str;
        if(str=="removeMin"){
            if(pq.empty()){
                pq.push(-1);
                stringovi.push_back("insert");
                brojevi.push_back(1);
            }
            pq.pop();
        }
        else if(str=="insert"){
            cin>>x;
            pq.push(-x);
            brojevi.push_back(x);
        }
        else if(str=="getMin"){
            cin>>x;
            while(!pq.empty() && -pq.top()<x){
                pq.pop();
                stringovi.push_back("removeMin");
            }
            if(pq.empty() || -pq.top()>x){
                pq.push(-x);
                stringovi.push_back("insert");
                brojevi.push_back(x);
            }
            brojevi.push_back(x);
        }
        stringovi.push_back(str);
    }
    long r=0;
    cout<<stringovi.size()<<endl;
    for(string i : stringovi){
        cout<<i;
        if(i!="removeMin"){cout<<" "<<brojevi[r];r++;}
        cout<<endl;
    }
    return 0;
}