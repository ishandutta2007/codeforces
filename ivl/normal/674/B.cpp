#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

void imp(){cout << -1 << endl; exit(0);}

int n, k;
int a, b, c, d;

bool taken[1005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  cin >> a >> b >> c >> d;
  taken[a] = taken[b] = taken[c] = taken[d] = true;

  if (n == 4) imp();
  if (k <= n) imp();
  if (k >= n+1){
    if (n == 5){
      int id = 15-a-b-c-d;
      cout << a << " " << c << " " << id << " " << d << " " << b << endl;
      cout << c << " " << a << " " << id << " " << b << " " << d << endl;
      return 0;
    }
    int id = 1;
    while (taken[id]) ++id; taken[id] = true;
    int id2 = 1;
    while (taken[id2]) ++id2; taken[id2] = true;

    cout << a << " " << c << " " << id << " ";
    FOR(i,1,n+1) if (!taken[i]) cout << i << " ";
    cout << id2 << " " << d << " " << b << endl;

    cout << c << " " << a << " " << id << " ";
    FOR(i,1,n+1) if (!taken[i]) cout << i << " ";
    cout << id2 << " " << b << " " << d << endl;
  }
  
  return 0;
}