#include <iostream>
using namespace std;

enum Location {
	Down=1,Up,Left,Right,Exist
};

typedef long long int ll;

struct pt{
	int x,y;
	int num;
	pt(int a=0,int b=0, int k=-1): x(a),y(b),num(k) {}
	pt(const pt& p): x(p.x),y(p.y),num(p.num) {}
	friend istream& operator >>(istream &is,pt& p){
		is >> p.x >> p.y;
		return is;
	}
	const pt& operator =(const pt& p){
		x=p.x;
		y=p.y;
		num = p.num;
		return *this;
	}
	Location loc(pt p){
		if(p.num==-1) return Exist;
		if(y<p.y)
			return Down;
		if(y>p.y)
			return Up;
		if(x<p.x)
			return Left;
		return Right;
	}
};


int main()
{
	int n;
	pt p1,p2,p3,p4,p5,cur;
	pt *p;
	bool additional=false;
	cin >> n;
	p = new pt [n];
	for(int i=0;i<n;++i){
		cin >> cur;
		cur.num=i+1;
		p[i] = cur;
		switch(cur.loc(p1)){
		case Exist:
			p1 = cur;
			continue;
			break;
		case Down:
			p5 = p3;
			p4 = p2;
			p3 = p1;
			p2 = pt();
			p1 = cur;
			continue;
			break;
		case Left:
			p2 = p1;
			p1 = cur;
			continue;
			break;
		case Right:
			switch(cur.loc(p2)){
			case Left:
			case Exist:
				p2 = cur;
			}
			continue;
			break;
		case Up:
			switch(cur.loc(p3)){
			case Exist:
				p3 = cur;
				continue;
				break;
			case Down:
				p5 = p3;
				p4 = pt();
				p3 = cur;
				continue;
				break;
			case Left:
				p4 = p3;
				p3 = cur;
				continue;
				break;
			case Right:
				switch(cur.loc(p4)){
				case Left:
				case Exist:
					p4 = cur;
				}
				continue;
				break;
			case Up:
				switch(cur.loc(p5)){
				case Down:
				case Left:
				case Exist:
					p5 = cur;
					break;
				default:
					break;
				}
			}
		}
	}
	if(p2.num==-1){
		if(p4.num==-1){
			ll q =((ll)(p1.x-p3.x))*((ll)(p5.y-p3.y))-((ll)(p1.y-p3.y))*((ll)(p5.x-p3.x));
			if(q==0){
				additional=true;
			}else{
				cout << p1.num << " " << p3.num << " " << p5.num;
			}
		}else{
			cout << p1.num << " " << p3.num << " " << p4.num;
		}
	}else{
		cout << p1.num << " " << p2.num << " " << p3.num;
	}
	if(additional){
		ll res;
		int index=-1;
		ll min=-1;
		int y_min=p1.y;
		for(int i=0;i<n;++i){
			if(i==p1.num-1 || i==p3.num-1 || i==p5.num-1){
				continue;
			}
			res = ((ll)(p[i].x-p1.x))*((ll)(p3.y-p1.y))-((ll)(p[i].y-p1.y))*((ll)(p3.x-p1.x));
			if(res<0){
				res=-res;
			}
			if((res!=0)&&((min==-1)||(min>res && (y_min>p[i].y)))){
				y_min=p[i].y;
				min=res;
				index=i;
			}
		}
		cout << p1.num << " " << p3.num << " " << p[index].num;
	}
	return 0;
}