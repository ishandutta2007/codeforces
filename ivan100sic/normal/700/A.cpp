#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

double x_deca, x_bus, v_deca, v_bus, duzina, dt;
int br_deca, c_bus, deca;
bool bus_deca;

bool probaj(double target){
	deca = br_deca;
	bus_deca = true;
	x_deca = 0;
	x_bus = 0;
	while (deca > 0){
		//cerr << deca << ' ' << x_deca << ' ' << target << endl;
		if (bus_deca){
			
			// ako ne mora da ih vozim super
			if (duzina - x_deca <= v_deca * target) return true;
			
			// ako ne mogu ni busom da stignu jebiga
			if (duzina - x_deca > v_bus * target) return false;
		
			// prevezi decu toliko taman da stignu na vreme
			double dist = v_bus * (duzina - target * v_deca - x_deca) / (v_bus - v_deca);
		
			dt = dist / v_bus;
			target -= dt;
			x_deca += dt * v_deca;
			x_bus += dist;
			deca -= c_bus;
			bus_deca = false;
		} else {
			// vrati se po decu
			dt = (x_bus - x_deca) / (v_bus + v_deca);
			x_deca += dt * v_deca;
			x_bus = x_deca;
			target -= dt;
			bus_deca = true;
		}
	}
	return true;
}

int main(){
	cin >> br_deca >> duzina >> v_deca >> v_bus >> c_bus;

	double l = 0, r = 1e10, m;
	int step = 100;
	while (step--){
		m = (l+r)/2;
		if (probaj(m)){
			r = m;
		} else {
			l = m;
		}
		//cerr << endl;
	}
	cout << setprecision(20) << m << endl;
}