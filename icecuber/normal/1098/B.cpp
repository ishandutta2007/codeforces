#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[150000];
string out[12][150000];

int main() {
  ios::sync_with_stdio(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int k = 0; k < 12; k++)
      out[k][i].resize(w);
  }
  string p[6] = {"AC","GT","AG","CT","AT","CG"};

  //horisontal
  for (int k = 0; k < 6; k++) {
    for (int i = 0; i < h; i++) {
      int bads[2] = {};
      for (int l = 0; l < 2; l++)
	for (int j = 0; j < w; j++)
	  if (s[i][j] != p[k^i&1][j&1^l])
	    bads[l]++;
      int l = bads[1] < bads[0];
      for (int j = 0; j < w; j++)
	out[k][i][j] = p[k^i&1][j&1^l];
    }
  }

  //vertical
  for (int k = 0; k < 6; k++) {
    for (int i = 0; i < w; i++) {
      int bads[2] = {};
      for (int l = 0; l < 2; l++)
	for (int j = 0; j < h; j++)
	  if (s[j][i] != p[k^i&1][j&1^l])
	    bads[l]++;
      int l = bads[1] < bads[0];
      for (int j = 0; j < h; j++)
	out[k+6][j][i] = p[k^i&1][j&1^l];
    }
  }
  int best = 1e9, bestk;
  for (int k = 0; k < 12; k++) {
    int bads = 0;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
	bads += s[i][j] != out[k][i][j];
    if (bads < best) best = bads, bestk = k;
  }
  for (int i = 0; i < h; i++)
    cout << out[bestk][i] << '\n';
}