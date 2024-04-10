t = int(input())

def f(s, n):
    if n == 1:
        return [s]
    
    cap = s-(n-1)
    strcap = str(cap)
    outval = '1'
    while len(outval) < len(strcap):
        outval += '0'
    outval = int(outval)
    recursestuff = f(s-outval, n-1)
    recursestuff.append(outval)
    return recursestuff

for _ in range(t):
    s, n = map(int, input().split())
    for x in f(s, n):
        print(x, end=" ")
    print()