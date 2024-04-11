// for CodeChef: WHAT'S WRONG WITH YOU GUYS??? WTF IS PENTIUM 3??? PLEASE UPGRADE SERVERS! IT'S RIDICULOUS TO TEST SOLUTIONS ON 9-YEAR OLD SYSTEM!

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <memory.h>
#include <map>

using namespace std;

#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back

typedef pair <int, int> pi;
typedef long long li;
typedef double ld;
#define FILE "change me!"

void solve();
//int timer=0;
int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
#else
	//freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
	//freopen (FILE ".in", "r", stdin);
	//freopen (FILE ".out", "w", stdout);
#endif
	int z=1;
	ios_base::sync_with_stdio(false);
	//cin>>z;
	while (z--)
		solve();
	return 0;
}


const int MAXN=200500;

//#define int li

void solve(){
    int n, k;
    cin>>n>>k;
    for (int l=0; ; ++l){
        if (k>=3*n-l && k<=5*n-3*l){
            cout<<l;
            return;
        }
    }
}