#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 100005;

int N, M;
int vests[MAX_N];
int soldiers[MAX_N];

int X, Y;
vector<pii> wear;

int main() {
    scanf("%d %d %d %d",&N,&M,&X,&Y);

    for(int i=0;i<N;i++) {
        scanf("%d",&soldiers[i]);
    }

    for(int i=0;i<M;i++) {
        scanf("%d",&vests[i]);
    }

    int upto = 0;
    for(int i=0;i<M;i++) {
        while(upto < N && soldiers[upto]+Y < vests[i]) {
            upto++;
        }

        if(upto < N && soldiers[upto]-X <= vests[i] && vests[i] <= soldiers[upto]+Y) {
            wear.push_back(make_pair(upto+1, i+1));
            upto++;
        }
    }

    printf("%d\n",wear.size());

    for(int i=0;i<wear.size();i++) {
        printf("%d %d\n",wear[i].first,wear[i].second);
    }

    return 0;
}