#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
#define INF 100000000

vector<int> adj[3111];

int dist[3111][3111];
int farthest_f[3111];
int farthest_b[3111];
int nfarthest_f[3111];
int nfarthest_b[3111];
int n2farthest_f[3111];
int n2farthest_b[3111];
int main() {
    int n, e;
    sf("%d%d", &n, &e);
    fr(ee,e) {
        int i, j;
        sf("%d%d", &i, &j);
        i--, j--;
        adj[i].push_back(j);
    }
    fr(i,n) {
        fr(j,n) dist[i][j] = -INF;
        vector<int> queue;
        queue.push_back(i);
        dist[i][i] = 0;
        fr(f,queue.size()) {
            int ci = queue[f];
            fr(nb,adj[ci].size()) {
                int j = adj[ci][nb];
                if (dist[i][j] < 0) {
                    dist[i][j] = dist[i][ci] + 1;
                    queue.push_back(j);
                }
            }
        }
    }
    fr(i,n) {
        farthest_f[i] = farthest_b[i] = -1;
        nfarthest_f[i] = nfarthest_b[i] = -1;
        fr(j,n) if (i != j) {
            if (farthest_f[i] < 0 || dist[i][farthest_f[i]] < dist[i][j]) {
                n2farthest_f[i] = nfarthest_f[i];
                nfarthest_f[i] = farthest_f[i];
                farthest_f[i] = j;
            } else if (nfarthest_f[i] < 0 || dist[i][nfarthest_f[i]] < dist[i][j]) {
                n2farthest_f[i] = nfarthest_f[i];
                nfarthest_f[i] = j;
            } else if (n2farthest_f[i] < 0 || dist[i][n2farthest_f[i]] < dist[i][j]) {
                n2farthest_f[i] = j;
            }
            if (farthest_b[i] < 0 || dist[farthest_b[i]][i] < dist[j][i]) {
                n2farthest_b[i] = nfarthest_b[i];
                nfarthest_b[i] = farthest_b[i];
                farthest_b[i] = j;
            } else if (nfarthest_b[i] < 0 || dist[nfarthest_b[i]][i] < dist[j][i]) {
                n2farthest_b[i] = nfarthest_b[i];
                nfarthest_b[i] = j;
            } else if (n2farthest_b[i] < 0 || dist[n2farthest_b[i]][i] < dist[j][i]) {
                n2farthest_b[i] = j;
            }
        }
    }
    int ans = -1;
    int cb = -1, ci = -1, cj = -1, cf = -1;
    fr(i,n) if(farthest_b[i] >= 0) fr(j,n) if (i != j && farthest_f[j] >= 0) {
        #define subok(A,B,C,D) do {\
            if (A >= 0 && D >= 0 && A != C && A != D && B != D) {\
                int cost = dist[A][B] + dist[B][C] + dist[C][D];\
                if (ans < cost) {\
                    ans = cost;\
                    cb = A;\
                    ci = B;\
                    cj = C;\
                    cf = D;\
                }\
            }\
        } while (0)
        subok(farthest_b[i], i, j, farthest_f[j]);
        subok(nfarthest_b[i], i, j, farthest_f[j]);
        subok(n2farthest_b[i], i, j, farthest_f[j]);
        subok(farthest_b[i], i, j, nfarthest_f[j]);
        subok(nfarthest_b[i], i, j, nfarthest_f[j]);
        subok(n2farthest_b[i], i, j, nfarthest_f[j]);
        subok(farthest_b[i], i, j, n2farthest_f[j]);
        subok(nfarthest_b[i], i, j, n2farthest_f[j]);
        subok(n2farthest_b[i], i, j, n2farthest_f[j]);
    }
    pf("%d %d %d %d\n", cb+1, ci+1, cj+1, cf+1);
}