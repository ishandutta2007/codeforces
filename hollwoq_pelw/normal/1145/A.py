n = int(input())
a = [[int(k) for k in input().split()]]
flag = [sorted(k) == k for k in a]
while (sum(flag)==0):
    b = []
    n//=2
    for k in a:
        b.append(k[:n])
        b.append(k[n:])
    a = b
    flag = [sorted(k) == k for k in a]
print(n)