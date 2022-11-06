def main():
    n, m = [int(i) for i in input().split()]
    
    result = 0
    current = 1
    
    houses = (int(i) for i in input().split())
    for i in houses:
        result += (n + i - current) % n
        current = i
    
    print(result)

main()