def main():
    n = int(input())
    v, *a = [int(i) for i in input().split()]
    for i in range(1002):
        t = max(a)
        if v > t:
            print(i)
            break
        a.append(t - 1)
        a.remove(t)
        v += 1
        
    
    
main()