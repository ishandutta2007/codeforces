#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <string>
using namespace std;
// Sumber : https://abitofcs.blogspot.co.id/2015/12/codeforces-586f-lizard-era-beginning.html
/*
a+a' = b+b' = c+c'
<=> a-b = -(a'-b') and b-c = -(b'-c')

say (a-b, b-c) = (dab, dbc) are fixed
we want to find another (dab', dbc') with dab = -dab' and dac = -dac'
such that a+a' is maximised for a given (dab,dac)
given two (dab', dac', a') and (dab*, dac*, a*)
fixing a, we will want max(a', a*)

transform a,b,c to key:[a-b, b-c], value:[a, path]
*/

int val[30][3];
int n;
string path;
map<pair<int,int>,pair<int,string> > m[2];
string mp[] = {"MW\n","LW\n","LM\n"};
map<pair<int,int>,pair<int,string> >::iterator iter, ater;
int ans = (int) -1e9;
string sp;

void dfs(int k, int h, int x, int p, int q, int r) {
	// k : tipe dfs;	h : terminator;		x : index_now;		pqr : total sum
    if (h == 0) { // kalo sudah TERAKHIR dan AKAN TERMINATE
        if (k == 0) { // k == 0 (UPPER PART)
            iter = m[1].find(make_pair(-p+q,-q+r)); // Cari di map, apa ada temennya
            if (iter != m[1].end()) {	// kalo ada, berarti dia bisa dijadiin solusi
                if (ans < p + iter->second.first) {		// kalo ANS saat ini itu lbh jelek dari a + a'
                    ans = p + iter->second.first;		// UPDATE ANS dan PATH dan ITER UPPER PART
                    ater = iter;
                    sp = path;
                }
            }
        } else { // k == 1 (LOWER PART)
            iter = m[k].find(make_pair(p-q,q-r)); // Coba cari di map, apa sudah pernah ada (a-b, b-c)
            if (iter != m[k].end()) { // iter ketemu
                if (iter->second.first < p) {	// kalo yg terakhir disimpan lbh jelek, REPLACE
                    iter->second.first = p;
                    iter->second.second = path;
                }
            } else { // TIDAK KETEMU
                m[k][make_pair(p-q,q-r)] = make_pair(p, path); // masukin aja a' dan solusinya
            }
        }
        return;
    }
    path += mp[0];	// coba masukin 'MW'
    dfs(k, h-1, x+1, p, q+val[x][1], r+val[x][2]);	// lanjutin dfs
    path.erase(path.size()-3); // hapus 'MW'
    path += mp[1];
    dfs(k, h-1, x+1, p+val[x][0], q, r+val[x][2]);
    path.erase(path.size()-3);
    path += mp[2];
    dfs(k, h-1, x+1, p+val[x][0], q+val[x][1], r);
    path.erase(path.size()-3);
}

int main(){
    scanf("%d",&n); // baca n
    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j){
            scanf("%d",&val[i][j]); // baca l, m, w
        }
    }
    if (n == 1) { // SPECIAL CASE : n == 1
        for(int i = 0; i < 3; ++i) {
            int j = (i+1)%3;
            if (val[0][i] == val[0][j] && !val[0][i]) {
                cout << mp[(i+2)%3];
                return 0;
            }
        }
        printf("Impossible\n");
        return 0;
    }
    int h = n/2;
    dfs(1, h, n-h, 0, 0, 0);
    dfs(0, n-h, 0, 0, 0, 0);
    if (ans > (int) -1e9) {
        //printf("%d\n",ans);
        cout << sp;
        cout << (ater->second.second);
    } else {
        printf("Impossible\n");
    }
    return 0;
}