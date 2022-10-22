#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll,ll> point;
#define x first
#define y second

ull mask[300][300][5];

inline ll popcount64c(uint64_t x) {
  const uint64_t m1  = 0x5555555555555555; //binary: 0101...
  const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
  const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
  const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
  const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
  const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
  const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
  x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
  x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits
  x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits
  return (x * h01) >> 56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ...
}

point p[300];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y;

  ll triples = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll nx =-(p[j].y-p[i].y);
      ll ny =  p[j].x-p[i].x;
      ll right = 0;
      for (int k = 0; k < n; k++) {
	ull ok = nx*(p[k].x-p[i].x)+ny*(p[k].y-p[i].y)>0;
	mask[i][j][k>>6] |= ok<<(k&63);
	right += ok;
      }
      triples += right*(right-1)*(right-2)/6;
    }
  }

  ll z = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < i && k < j; k++) {
	if (!(mask[i][j][k>>6]>>(k&63)&1)) continue;
	//cout << i << ' ' << j << ' ' << k << endl;
	ll insides = 0;
	for (int l = 0; l < 5; l++) {
	  ull inside = mask[i][j][l]&mask[j][k][l]&~mask[i][k][l];
	  insides += popcount64c(inside);
	}
	z += insides*(insides-1)/2;
      }
    }
  }
  ll tot = 1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/120;
  cout << triples-tot*4+z << endl;

}