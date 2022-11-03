#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 100002;
const int mod = 1000000007;
const double eps = 1e-6;

void mix(int arr[3],int i){
    if(i%3==0){
        swap(arr[0],arr[2]);
        return;
    }
    swap(arr[0],arr[1]);
    swap(arr[1],arr[2]);
}

int v[8][3];

double dist(double x,double y,double z,double x0,double y0,double z0){
    return sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0)+(z-z0)*(z-z0));
}

bool isEqual(vector<double> &vec){
    double w[] = {1,1,1,sqrt(2),sqrt(2),sqrt(2),sqrt(3)};
    for(int i=0;i<7;i++){
        if(fabs(vec[i]-w[i])>eps){
            return false;
        }
    }
    return true;
}

bool cube()
{
    double x=0,y=0,z=0;
    for(int i=0;i<8;i++){
        x += v[i][0];
        y += v[i][1];
        z += v[i][2];
    }
    x /= 8;
    y /= 8;
    z /= 8;
    double r = dist(x,y,z,v[0][0],v[0][1],v[0][2]);
    if(fabs(r)<eps){
        return false;
    }
    for(int i=1;i<8;i++){
        if(fabs(dist(x,y,z,v[i][0],v[i][1],v[i][2])-r)>eps){
            return false;   
        }
    }
    vector<double> d;
    for(int i=0;i<8;i++){
        d.clear();
        for(int j=0;j<8;j++){
            if(j==i){
                continue;
            }
            d.push_back(dist(v[i][0],v[i][1],v[i][2],v[j][0],v[j][1],v[j][2])/r*sqrt(3)*0.5);
        }
        sort(d.begin(),d.end());
        if(!isEqual(d)){
            return false;
        }
    }
    return true;
}

int main()
{
    int a;
    for(int i=0;i<8;i++){
        for(int j=0;j<3;j++){
            cin >> a;
            v[i][j] = a;
        }
    }
    bool ans = false;
    for(int a1=0;a1<6;a1++){
        mix(v[0],a1);
        for(int a2=0;a2<6;a2++){
            mix(v[1],a2);
            for(int a3=0;a3<6;a3++){
                mix(v[2],a3);
                for(int a4=0;a4<6;a4++){
                    mix(v[3],a4);
                    for(int a5=0;a5<6;a5++){
                        mix(v[4],a5);
                        for(int a6=0;a6<6;a6++){
                            mix(v[5],a6);
                            for(int a7=0;a7<6;a7++){
								mix(v[6],a7);
								if(cube()){
									ans = true;
									break;
								}
							}
							if(ans){
								break;
							}
                        }
						if(ans){
							break;
						}
                    }
					if(ans){
						break;
					}
                }
				if(ans){
					break;
				}
            }
			if(ans){
				break;
			}
        }
		if(ans){
			break;
		}
    }
    if(!ans){
        cout << "NO";
    }else{
        cout << "YES";
        for(int i=0;i<8;i++){ 
            cout << "\n";
            for(int j=0;j<3;j++){
                if(j){
                    cout << " ";
                }
                cout << v[i][j];
            }
        }
    }
}