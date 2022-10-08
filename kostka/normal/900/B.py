from fractions import Fraction

(a, b, c) = tuple(map(int, input().split()))
f = Fraction(a, b)
for i in range(900):
    for j in range(10):
        if f < Fraction(j+1, 10):
            if j == c:
                print(i+1)
                exit(0)
            f -= Fraction(j, 10)
            f *= 10
            break
print(-1)