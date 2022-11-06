def void():
	return

def doNext(f, g):
	f()
	g()
	return void

def doList(xs):
	reduce(doNext, xs, void)
	return

def printF(n):
	print n
	return void

a = []

def readStr(n):
	global a
	a.append(map(int, raw_input().split()))
	return void

def relax(t):
	global a
	(k, i, j) = t
	a[i][j] = min(a[i][j], a[i][k] + a[k][j])
	return void

n = int(raw_input())

ls = [[]]

def addTo(x):
	def f(y):
		xx = x[:]
		xx.append(y)
		return xx
	return f

def addToAll():
	global ls
	ls = reduce(lambda x, y: x + y, map(lambda x: map(addTo(x), range(n)), ls), [])
	#ls = map(lambda x: map(addTo(x), range(n)), ls)
	return void

map(readStr, [0]*n)
addToAll()
addToAll()
addToAll()
#print map(addTo([]), [0])
map(relax, ls)
print max(map(max, a))