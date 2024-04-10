#include<bits/stdc++.h>
//This code is written by Itst
#define st first
#define nd second
#define PII pair < int , int >
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
queue < PII > q[10];
char Map[1010][1010];
bool vis[1010][1010];
int N , M , P , cnt , len[10] , ans[10] , allCnt;
 
inline void out(int x){
	for(int i = 1 ; q[x].size() && i <= len[x] ; ++i)
		for(int j = q[x].size() ; j ; --j){
			PII t = q[x].front();
			q[x].pop();
			if(vis[t.st][t.nd])
				continue;
			vis[t.st][t.nd] = 1;
			++allCnt;
			++ans[x];
			for(int j = 0 ; j < 4 ; ++j)
				if(!vis[t.st + dir[j][0]][t.nd + dir[j][1]])
					if(t.st + dir[j][0] > 0 && t.st + dir[j][0] <= N)
						if(t.nd + dir[j][1] > 0 && t.nd + dir[j][1] <= M)
							q[x].push(PII(t.st + dir[j][0] , t.nd + dir[j][1]));
		}
}

inline char getc(){
	char c = getchar();
	while(c == '\r' || c == '\n')
		c = getchar();
	return c;
}

int main(){
	cin >> N >> M >> P;
	for(int i = 1 ; i <= P ; ++i)
		cin >> len[i];
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j){
			Map[i][j] = getc();
			if(Map[i][j] == '#'){
				vis[i][j] = 1;
				++allCnt;
			}
			else
				if(isdigit(Map[i][j])){
					vis[i][j] = 1;
					++allCnt;
					++ans[Map[i][j] - '0'];
				}
			}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if(isdigit(Map[i][j]))
				for(int k = 0 ; k < 4 ; ++k)
					if(!vis[i + dir[k][0]][j + dir[k][1]])
						if(i + dir[k][0] > 0 && i + dir[k][0] <= N)
							if(j + dir[k][1] > 0 && j + dir[k][1] <= M)
								q[Map[i][j] - '0'].push(PII(i + dir[k][0] , j + dir[k][1]));
	while(allCnt != N * M){
		bool f = 1;
		for(int i = 1 ; i <= P ; ++i)
			if(!q[i].empty())
				f = 0;
		if(f)
			break;
		for(int i = 1 ; i <= P ; ++i)
			out(i);
	}
	for(int i = 1 ; i <= P ; ++i)
		cout << ans[i] << ' ';
	return 0;
}