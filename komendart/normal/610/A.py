def main():
    n = int(input())
    if n % 2 == 1:
        print(0)
    else:
        print(((n // 2) - 1) // 2)
    
    
main()