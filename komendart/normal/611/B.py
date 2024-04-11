def f(x):
    res = 0
    for i in range(64):
        for j in range(i + 1, 64):
            t = 0
            for k in range(j + 1):
                if k != i:
                    t += 1 << k
            if t <= x:
                res += 1
    return res
    

def main():
    a, b = [int(i) for i in input().split()]
    print(f(b) - f(a - 1))
    
    
main()