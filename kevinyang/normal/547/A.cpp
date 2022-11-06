#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> m;
	int h1,a1;
	cin >> h1 >> a1;
	int x1,y1;
	cin >> x1 >> y1;
	int h2,a2;
	cin >> h2 >> a2;
	int x2,y2;
	cin >> x2 >> y2;
	int existonce = 0;
	int existonce2 = 0;
	int largerthan = 0;
	int largerthan2 = 0;
	int modlength = 0;
	int modlength2 = 0;
	if(true){
		vector<int>dis(m+1,(int)1e18);
		dis[h1] = 0;
		queue<int>q;
		q.push(h1);
		int repeatnode = 0;
		int repeatlength = 0;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			int dist = dis[cur]+1;
			int nxt = x1*cur+y1;
			nxt%=m;
			if(dis[nxt]!=(int)1e18){
				repeatnode = nxt;
				repeatlength = dist-dis[nxt];
				break;
			}
			else{
				dis[nxt] = dist;
				q.push(nxt);
			}
		}
		if(dis[a1]==(int)1e18){
			cout << "-1\n";
			return 0;
		}
		if(true){
			if(dis[a1]>=dis[repeatnode]&&dis[a1]<dis[repeatnode]+repeatlength){
				modlength = repeatlength;
				largerthan = dis[a1];
			}
			else{
				existonce = dis[a1];
				largerthan = dis[a1];
			}
		}
	}
	if(true){
		vector<int>dis(m+1,(int)1e18);
		dis[h2] = 0;
		queue<int>q;
		q.push(h2);
		int repeatnode = 0;
		int repeatlength = 0;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			int dist = dis[cur]+1;
			int nxt = x2*cur+y2;
			nxt%=m;
			if(dis[nxt]!=(int)1e18){
				repeatnode = nxt;
				repeatlength = dist-dis[nxt];
				break;
			}
			else{
				dis[nxt] = dist;
				q.push(nxt);
			}
			//cout << nxt << "nae ";
		}
		//cout << "\n";
		if(dis[a2]==(int)1e18){
			cout << "-1\n";
			return 0;
		}
		if(true){
			if(dis[a2]>=dis[repeatnode]&&dis[a2]<dis[repeatnode]+repeatlength){
				modlength2 = repeatlength;
				largerthan2 = dis[a2];
			}
			else{
				existonce2 = dis[a2];
				largerthan2 = dis[a2];
			}
		}
	}
	//cerr << "nae\n";
	//cout << largerthan << " " << modlength << "\n";
	//cout << largerthan2 << " " << modlength2 << "\n";
	if(existonce&&existonce2){
		if(existonce==existonce2){
			cout << existonce << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
	else if(existonce){
		int cur = largerthan2;
		while(cur<existonce){
			cur+=modlength2;
		}
		if(cur==largerthan){
			cout << largerthan << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
	else if(existonce2){
		int cur = largerthan;
		while(cur<existonce2){
			cur+=modlength;
		}
		if(cur==largerthan2){
			cout << largerthan2 << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
	else{
		int cur = largerthan; int cur2 = largerthan2;
		for(int i = 0; i<2100000; i++){
			if(cur==cur2)break;
			if(cur<cur2)cur+=modlength;
			else cur2+=modlength2;
		}
		if(cur==cur2)cout << cur << "\n";
		else cout << "-1\n";
	}
	return 0;
}