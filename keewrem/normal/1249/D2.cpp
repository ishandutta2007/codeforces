#include <bits/stdc++.h>
using namespace std;

int N,K,a,b;
vector <pair<int,int>> v;
bitset<200100> removed;
vector <int> res;
int ed[200100];
int seg = 0;
priority_queue<pair<int,int>> pq;
pair <int,int> x;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1 ; i <= N ; i++) {
        scanf("%d %d", &a, &b);
        ed[i]=b;
        v.push_back(make_pair(b,i));
        v.push_back(make_pair(a,-i));
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < v.size(); i++){
        x = v[i];
        if(x.second > 0){
            if(!removed[x.second])seg--;
            continue;
        }
        x.second = -x.second;
        seg++;
        pq.push(make_pair(ed[x.second],x.second));
        if(seg > K){
            seg --;
            res.push_back(pq.top().second);
            removed[pq.top().second]=1;
            pq.pop();
        }
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++)cout << res[i] << "\n";
    return 0;

}