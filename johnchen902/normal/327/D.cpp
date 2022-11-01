#include <iostream>
#include <stack>
#include <utility>

using namespace std;

struct Point{
	int y, x;
};

int h, w;
char arr[501][501]; // y, x
bool isPushed[500][500];
stack<Point> s;

template<class CallBack>
inline void checkPush(int y, int x, CallBack&& callback, bool& hold){
	if( y >= 0 && y < h && x >= 0 && x < w && !isPushed[y][x]){
		isPushed[y][x] = true;
		s.push(Point{y, x});
		callback('B', y, x);
		hold = true;
	}
}
template<class CallBack>
void dfs(int by, int bx, CallBack&& callback){
	isPushed[by][bx] = true;
	s.push(Point{by, bx});
	callback('B', by, bx);
	while(!s.empty()){
		Point p = s.top();
		bool hold = false;
		checkPush(p.y, p.x + 1, callback, hold);
		checkPush(p.y, p.x - 1, callback, hold);
		checkPush(p.y + 1, p.x, callback, hold);
		checkPush(p.y - 1, p.x, callback, hold);
		if(!hold){
			s.pop();
			if(!s.empty()){
				callback('D', p.y, p.x);
				callback('R', p.y, p.x);
			}
		}
	}
}
template<class CallBack>
void dfsAll(CallBack&& callback){
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			isPushed[i][j] = arr[i][j] == '#';
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			if(!isPushed[i][j])
				dfs(i, j, callback);
}
class Inc{
public:
	int i;
	Inc():i(0){
	}
	void operator() (char, int, int){
		i++;
	}
};
class Print{
public:
	void operator() (char c, int y, int x) {
		cout << c << " " << y + 1 << " " << x + 1 << endl;
	}
};
int main(){
	cin >> h >> w;
	for(int i = 0; i < h; i++)
		cin >> arr[i];
	Inc inc;
	dfsAll(inc);
	cout << inc.i << endl;
	dfsAll(Print());
	return 0;
}