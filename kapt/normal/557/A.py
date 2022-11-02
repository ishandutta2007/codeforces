n = int (input())
R = lambda: map (int, input().split())
Min1, Max1 = R()
Min2, Max2 = R()
Min3, Max3 = R()

a = Max1
b = Max2
c = n - a - b

if c < Min3:
    c = Min3
    b = n - a - c
if b < Min2:
    b = Min2
    a = n - b - c


print (a,b,c)