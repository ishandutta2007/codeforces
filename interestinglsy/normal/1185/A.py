a,b,c,d = map(int,input().split())
if a > b: a,b = b,a
if b > c: b,c = c,b
if a > b: a,b = b,a
if b > c: b,c = c,b
if a > b: a,b = b,a
if b > c: b,c = c,b
if a > b: a,b = b,a
if b > c: b,c = c,b
if a > b: a,b = b,a
if b > c: b,c = c,b
if a > b: a,b = b,a
if b > c: b,c = c,b
print( max(d-(b-a),0) + max(d-(c-b),0) )