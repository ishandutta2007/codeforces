n = int(input())
a = list(map(int,input().split())) + [ 0 for i in range(131072) ]

get = [ 0 for i in range(262144) ]
res = [ 0 for i in range(262144) ]
def Build(l,r,pos):
	if l == r:
		get[pos] = 0
		res[pos] = a[l]
		return
	Build(l,l+r>>1,pos<<1)
	Build((l+r>>1)+1,r,pos<<1|1)
	get[pos] = get[pos<<1] + get[pos<<1|1] + (res[pos<<1]+res[pos<<1|1])//10
	res[pos] = (res[pos<<1]+res[pos<<1|1]) % 10
def Query(gl,gr,l,r,pos):
	if gl <= l and r <= gr:
		return (get[pos],res[pos])
	mid = l+r >> 1
	if gr <= mid: return Query(gl,gr,l,mid,pos<<1)
	if gl > mid: return Query(gl,gr,mid+1,r,pos<<1|1)
	(lget,lres) = Query(gl,gr,l,mid,pos<<1)
	(rget,rres) = Query(gl,gr,mid+1,r,pos<<1|1)
	return (lget+rget+(lres+rres)//10,(lres+rres)%10)

Build(0,131071,1)

q = int(input())
for i in range(q):
	l,r = map(int,input().split())
	print(Query(l-1,r-1,0,131071,1)[0])