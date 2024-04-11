#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

void addprime(){
    v.push_back(13);
    v.push_back(19);
    v.push_back(31);
    v.push_back(37);
    v.push_back(43);
    v.push_back(53);
    v.push_back(61);
    v.push_back(79);
    v.push_back(101);
    v.push_back(113);
    v.push_back(139);
    v.push_back(163);
    v.push_back(173);
    v.push_back(199);
    v.push_back(211);
    v.push_back(223);
    v.push_back(241);
    v.push_back(269);
    v.push_back(277);
    v.push_back(331);
    v.push_back(353);
    v.push_back(373);
    v.push_back(397);
    v.push_back(457);
    v.push_back(463);
    v.push_back(509);
    v.push_back(521);
    v.push_back(541);
    v.push_back(577);
    v.push_back(601);
    v.push_back(619);
    v.push_back(631);
    v.push_back(727);
    v.push_back(773);
    v.push_back(787);
    v.push_back(811);
    v.push_back(829);
    v.push_back(853);
    v.push_back(883);
    v.push_back(907);
    v.push_back(919);
    v.push_back(947);
    v.push_back(967);
    v.push_back(991);
}

int main(){
    addprime();
    int n, k;
    scanf("%d %d",&n,&k);
    int cnt = (int)(upper_bound(v.begin(),v.end(),n) - v.begin());
    puts(cnt >= k ? "YES" : "NO");
}