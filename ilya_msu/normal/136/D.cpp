#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

struct point {
	int x, y;
};

struct vec {
	int x, y;
	bool operator == (vec rhs) {
		return ((x == rhs.x) && (y == rhs.y));
	}
	int d() {
		return x * x + y * y;
	}
	
};

int scal(vec lhs, vec rhs) {
		return (lhs.x * rhs.x + lhs.y * rhs.y);
}


bool checkPr(vector<point> data) {
	vec v1, v2, v3, v4;
	vec z;
	z.x = z.y = 0;
	v1.x = data[1].x - data[0].x;
	v1.y = data[1].y - data[0].y;
	v2.x = data[2].x - data[1].x;
	v2.y = data[2].y - data[1].y;
	v3.x = -data[3].x + data[2].x;
	v3.y = -data[3].y + data[2].y;
	v4.x = -data[0].x + data[3].x;
	v4.y = -data[0].y + data[3].y;
	if ((v1 == v3) && (v2 == v4)) {
		if (z == v1)
			return false;
		if (z == v2)
			return false;
		if (z == v3)
			return false;
		if (z == v4)
			return false;
		if (scal(v1, v2) == 0)
			return true;
	}
	return false;
}

bool checkSq(vector<point> data) {
	vec v1, v2, v3, v4;
	vec z;
	z.x = z.y = 0;
	v1.x = data[1].x - data[0].x;
	v1.y = data[1].y - data[0].y;
	v2.x = data[2].x - data[1].x;
	v2.y = data[2].y - data[1].y;
	v3.x = -data[3].x + data[2].x;
	v3.y = -data[3].y + data[2].y;
	v4.x = -data[0].x + data[3].x;
	v4.y = -data[0].y + data[3].y;
	if ((v1 == v3) && (v2 == v4)) {
		if (z == v1)
			return false;
		if (z == v2)
			return false;
		if (z == v3)
			return false;
		if (z == v4)
			return false;
		if ((scal(v1, v2) == 0) && (v1.d() == v2.d()))
			return true;
	}
	return false;
}

int main() {
	vector<point> data(8);

	for (int i = 0; i < 8; ++i) {
		cin >> data[i].x >> data[i].y;
	}

	for (int i1 = 0; i1 < 8; ++i1) 
		for (int i2 = 0; i2 < i1; ++i2) 
			for (int i3 = 0; i3 < i2; ++i3) 
				for (int i4 = 0; i4 < i3; ++i4) {
					vector<point> sq(4);
					int j2, j3, j4;
					bool c = false;
					sq[0] = data[i1];
					j2 = i2;	j3 = i3;	j4 = i4;
					sq[1] = data[j2];	sq[2] = data[j3]; 	sq[3] = data[j4];
					c = c || checkSq(sq);
					j2 = i2;	j3 = i4;	j4 = i3;
					sq[1] = data[j2];	sq[2] = data[j3]; 	sq[3] = data[j4];
					c = c || checkSq(sq);
					j2 = i3;	j3 = i2;	j4 = i4;
					sq[1] = data[j2];	sq[2] = data[j3]; 	sq[3] = data[j4];
					c = c || checkSq(sq);
					j2 = i3;	j3 = i4;	j4 = i2;
					sq[1] = data[j2];	sq[2] = data[j3]; 	sq[3] = data[j4];
					c = c || checkSq(sq);
					j2 = i4;	j3 = i2;	j4 = i3;
					sq[1] = data[j2];	sq[2] = data[j3]; 	sq[3] = data[j4];
					c = c || checkSq(sq);
					j2 = i4;	j3 = i3;	j4 = i2;
					sq[1] = data[j2];	sq[2] = data[j3]; 	sq[3] = data[j4];
					c = c || checkSq(sq);
					if (c) {
					for (int i5 = 0; i5 < 8; ++i5) {
						if ((i5 != i1) && (i5 != i2) && (i5 != i3) && (i5 != i4))
						for (int i6 = 0; i6 < i5; ++i6)
							if ((i6 != i1) && (i6 != i2) && (i6 != i3) && (i6 != i4))
							for (int i7 = 0; i7 < i6; ++i7)
								if ((i7 != i1) && (i7 != i2) && (i7 != i3) && (i7 != i4))
								for (int i8 = 0; i8 < i7; ++i8) 
									if ((i8 != i1) && (i8 != i2) && (i8 != i3) && (i8 != i4)) {
										vector<point> pr(4);
										int k2, k3, k4;
										bool cc = false;
										pr[0] = data[i5];
										k2 = i6;	k3 = i7;	k4 = i8;
										pr[1] = data[k2];	pr[2] = data[k3]; 	pr[3] = data[k4];
										cc = cc || checkPr(pr);
										k2 = i6;	k3 = i8;	k4 = i7;
										pr[1] = data[k2];	pr[2] = data[k3]; 	pr[3] = data[k4];
										cc = cc || checkPr(pr);
										k2 = i7;	k3 = i6;	k4 = i8;
										pr[1] = data[k2];	pr[2] = data[k3]; 	pr[3] = data[k4];
										cc = cc || checkPr(pr);
										k2 = i7;	k3 = i8;	k4 = i6;
										pr[1] = data[k2];	pr[2] = data[k3]; 	pr[3] = data[k4];
										cc = cc || checkPr(pr);
										k2 = i8;	k3 = i6;	k4 = i7;
										pr[1] = data[k2];	pr[2] = data[k3]; 	pr[3] = data[k4];
										cc = cc || checkPr(pr);
										k2 = i8;	k3 = i7;	k4 = i6;
										pr[1] = data[k2];	pr[2] = data[k3]; 	pr[3] = data[k4];
										cc = cc || checkPr(pr);
										if (cc) {
											cout << "YES" << endl;
											cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << " " << i4 + 1 << endl;
											cout << i5 + 1 << " " << i6 + 1 << " " << i7 + 1 << " " << i8 + 1 << endl;
											return 0;
										}
									}
					}
					}
				}
	cout << "NO" << endl;	
	return 0;
}